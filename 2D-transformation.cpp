#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

// Define a Shape structure to represent either a 2D triangle or quadrilateral
struct Shape
{
  int x1, y1;
  int x2, y2;
  int x3, y3;
  int x4, y4;           // Added for quadrilateral
  bool isQuadrilateral; // Flag to indicate if the shape is a quadrilateral
};

// Function to draw a shape
void drawShape(const Shape &s, int color)
{
  setcolor(color);
  if (s.isQuadrilateral)
  {
    line(s.x1, s.y1, s.x2, s.y2);
    line(s.x2, s.y2, s.x3, s.y3);
    line(s.x3, s.y3, s.x4, s.y4);
    line(s.x4, s.y4, s.x1, s.y1);
  }
  else
  {
    line(s.x1, s.y1, s.x2, s.y2);
    line(s.x2, s.y2, s.x3, s.y3);
    line(s.x3, s.y3, s.x1, s.y1);
  }
}

// Function to draw x and y axes
void drawAxes(int width, int height)
{
  setcolor(WHITE); // Set color for the axes

  // Draw x-axis
  line(0, height / 2, width, height / 2);

  // Draw y-axis
  line(width / 2, 0, width / 2, height);
}

// Function to apply translation
void translate(Shape &s, int tx, int ty)
{
  s.x1 += tx;
  s.y1 += ty;
  s.x2 += tx;
  s.y2 += ty;
  s.x3 += tx;
  s.y3 += ty;
  s.x4 += tx;
  s.y4 += ty;
}

// Function to apply scaling
void scale(Shape &s, float sx, float sy, int cx, int cy)
{
  s.x1 = static_cast<int>(cx + (s.x1 - cx) * sx);
  s.y1 = static_cast<int>(cy + (s.y1 - cy) * sy);
  s.x2 = static_cast<int>(cx + (s.x2 - cx) * sx);
  s.y2 = static_cast<int>(cy + (s.y2 - cy) * sy);
  s.x3 = static_cast<int>(cx + (s.x3 - cx) * sx);
  s.y3 = static_cast<int>(cy + (s.y3 - cy) * sy);
  s.x4 = static_cast<int>(cx + (s.x4 - cx) * sx);
  s.y4 = static_cast<int>(cy + (s.y4 - cy) * sy);
}

// Function to apply rotation
void rotate(Shape &s, float angle, int cx, int cy)
{
  float radians = angle * M_PI / 180.0;
  auto rotatePoint = [cx, cy, radians](int &x, int &y)
  {
    int x_new = static_cast<int>(cx + (x - cx) * cos(radians) - (y - cy) * sin(radians));
    int y_new = static_cast<int>(cy + (x - cx) * sin(radians) + (y - cy) * cos(radians));
    x = x_new;
    y = y_new;
  };
  rotatePoint(s.x1, s.y1);
  rotatePoint(s.x2, s.y2);
  rotatePoint(s.x3, s.y3);
  rotatePoint(s.x4, s.y4);
}

// Function to apply shear
void shear(Shape &s, float shx, float shy)
{
  auto shearPoint = [shx, shy](int &x, int &y)
  {
    int x_new = static_cast<int>(x + shx * y);
    int y_new = static_cast<int>(shy * x + y);
    x = x_new;
    y = y_new;
  };
  shearPoint(s.x1, s.y1);
  shearPoint(s.x2, s.y2);
  shearPoint(s.x3, s.y3);
  shearPoint(s.x4, s.y4);
}

// Function to apply reflection
void reflect(Shape &s, char axis, int cx, int cy)
{
  if (axis == 'x' || axis == 'X')
  {
    s.y1 = 2 * cy - s.y1;
    s.y2 = 2 * cy - s.y2;
    s.y3 = 2 * cy - s.y3;
    s.y4 = 2 * cy - s.y4;
  }
  else if (axis == 'y' || axis == 'Y')
  {
    s.x1 = 2 * cx - s.x1;
    s.x2 = 2 * cx - s.x2;
    s.x3 = 2 * cx - s.x3;
    s.x4 = 2 * cx - s.x4;
  }
  else if (axis == 'o' || axis == 'O')
  {
    s.x1 = 2 * cx - s.x1;
    s.y1 = 2 * cy - s.y1;
    s.x2 = 2 * cx - s.x2;
    s.y2 = 2 * cy - s.y2;
    s.x3 = 2 * cx - s.x3;
    s.y3 = 2 * cy - s.y3;
    s.x4 = 2 * cx - s.x4;
    s.y4 = 2 * cy - s.y4;
  }
  else
  {
    cout << "Invalid axis for reflection." << endl;
  }
}

// Main function
int main()
{
  int gd = DETECT, gm;
  char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file
  initgraph(&gd, &gm, data);

  Shape s{200, 150, 250, 100, 300, 150, 0, 0, false}; // Initial triangle

  int choice;
  float tx, ty, sx, sy, angle, shx, shy;
  char axis;
  int width = getmaxx();
  int height = getmaxy();
  int cx = width / 2; // Center of the screen for transformations
  int cy = height / 2;

  while (true)
  {
    cleardevice(); // Clear the screen

    drawAxes(width, height); // Draw the axes
    drawShape(s, WHITE);     // Draw the shape

    // Display menu
    cout << "2D Transformation Menu" << endl;
    cout << "1. Enter a shape (triangle or quadrilateral)" << endl;
    cout << "2. Translate the shape" << endl;
    cout << "3. Scale the shape" << endl;
    cout << "4. Rotate the shape" << endl;
    cout << "5. Shear the shape" << endl;
    cout << "6. Reflect the shape" << endl;
    cout << "7. Display the shape" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter the type of shape (t for triangle, q for quadrilateral): ";
      char shapeType;
      cin >> shapeType;
      if (shapeType == 't' || shapeType == 'T')
      {
        s.isQuadrilateral = false;
        cout << "Enter the coordinates of the triangle (x1 y1 x2 y2 x3 y3): ";
        cin >> s.x1 >> s.y1 >> s.x2 >> s.y2 >> s.x3 >> s.y3;
      }
      else if (shapeType == 'q' || shapeType == 'Q')
      {
        s.isQuadrilateral = true;
        cout << "Enter the coordinates of the quadrilateral (x1 y1 x2 y2 x3 y3 x4 y4): ";
        cin >> s.x1 >> s.y1 >> s.x2 >> s.y2 >> s.x3 >> s.y3 >> s.x4 >> s.y4;
      }
      else
      {
        cout << "Invalid shape type. Defaulting to triangle." << endl;
        s.isQuadrilateral = false;
        cout << "Enter the coordinates of the triangle (x1 y1 x2 y2 x3 y3): ";
        cin >> s.x1 >> s.y1 >> s.x2 >> s.y2 >> s.x3 >> s.y3;
      }
      break;

    case 2:
      cout << "Enter translation factors (tx ty): ";
      cin >> tx >> ty;
      translate(s, static_cast<int>(tx), static_cast<int>(ty));
      break;

    case 3:
      cout << "Enter scaling factors (sx sy): ";
      cin >> sx >> sy;
      scale(s, sx, sy, cx, cy);
      break;

    case 4:
      cout << "Enter rotation angle (degrees): ";
      cin >> angle;
      rotate(s, angle, cx, cy);
      break;

    case 5:
      cout << "Enter shear factors (shx shy): ";
      cin >> shx >> shy;
      shear(s, shx, shy);
      break;

    case 6:
      cout << "Enter reflection axis (x, y, or o for both): ";
      cin >> axis;
      reflect(s, axis, cx, cy);
      break;

    case 7:
      if (s.isQuadrilateral)
      {
        cout << "Current quadrilateral coordinates: (" << s.x1 << ", " << s.y1 << "), "
             << "(" << s.x2 << ", " << s.y2 << "), "
             << "(" << s.x3 << ", " << s.y3 << "), "
             << "(" << s.x4 << ", " << s.y4 << ")" << endl;
      }
      else
      {
        cout << "Current triangle coordinates: (" << s.x1 << ", " << s.y1 << "), "
             << "(" << s.x2 << ", " << s.y2 << "), "
             << "(" << s.x3 << ", " << s.y3 << ")" << endl;
      }
      break;

    case 8:
      closegraph(); // Close the graphics window
      return 0;

    default:
      cout << "Invalid choice. Please try again." << endl;
      break;
    }
  }

  return 0;
}
