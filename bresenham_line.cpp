#include <graphics.h>
#include <conio.h>
#include <cstdlib>

// Function to draw a line using Bresenham's algorithm with delay
void bresenhamLineWithDelay(int x1, int y1, int x2, int y2, int delayMs) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        putpixel(x1, y1, WHITE);  // Draw the pixel
        delay(delayMs);           // Delay to slow down the drawing

        if (x1 == x2 && y1 == y2) break;

        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Example usage of Bresenham's line algorithm with delay
    int x1 = 100, y1 = 100;
    int x2 = 300, y2 = 200;
    int delayMs = 10; // Delay in milliseconds

    bresenhamLineWithDelay(x1, y1, x2, y2, delayMs);

    getch();
    closegraph();
    return 0;
}
