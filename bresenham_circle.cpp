#include <graphics.h>
#include <conio.h>
#include <cmath>
// #include <dos.h>  // For delay function (specific to Turbo C++ and older compilers)

// Function to draw a circle using Bresenham's circle algorithm with delay
void bresenhamCircle(int x0, int y0, int r) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;  // Initial decision parameter

    // Draw the initial 8 points of the circle
    while (x <= y) {
        putpixel(x0 + x, y0 + y, WHITE);
        putpixel(x0 - x, y0 + y, WHITE);
        putpixel(x0 + x, y0 - y, WHITE);
        putpixel(x0 - x, y0 - y, WHITE);
        putpixel(x0 + y, y0 + x, WHITE);
        putpixel(x0 - y, y0 + x, WHITE);
        putpixel(x0 + y, y0 - x, WHITE);
        putpixel(x0 - y, y0 - x, WHITE);

        delay(50);  // Delay in milliseconds

        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Example usage of Bresenham's circle algorithm
    int x0 = 300; // Center x-coordinate
    int y0 = 200; // Center y-coordinate
    int r = 100;  // Radius

    bresenhamCircle(x0, y0, r);

    getch();
    closegraph();
    return 0;
}
