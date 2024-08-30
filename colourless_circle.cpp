#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

// Function to draw a pixel using a rectangle for better visibility
void drawPixel(int x, int y, int color, int a, int b) {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    bar((a / 2 + x * 7), (b / 2 - y * 7), (a / 2 + x * 7 + 7), (b / 2 - y * 7 + 7));
}

// Function to plot all eight points of the circle based on the symmetry
void drawCirclePoints(int x, int y, int color, int a, int b) {
    drawPixel(x, y, color, a, b);
    drawPixel(-x, y, color, a, b);
    drawPixel(x, -y, color, a, b);
    drawPixel(-x, -y, color, a, b);
    drawPixel(y, x, color, a, b);
    drawPixel(-y, x, color, a, b);
    drawPixel(y, -x, color, a, b);
    drawPixel(-y, -x, color, a, b);
}

// Midpoint Circle Drawing Algorithm
void midpointCircle(int radius, int color, int a, int b) {
    int x = 0;
    int y = radius;
    int p = 5 / 4 - radius; // Initial decision parameter

    drawCirclePoints(x, y, color, a, b);

    while (x < y) {
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        x++;
        drawCirclePoints(x, y, color, a, b);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int a = getmaxx();
    int b = getmaxy();
    int radius = 30;
    int color = WHITE;

    while (1) {
        // Animate the circle shrinking
        while (radius > 0) {
            delay(20);
            cleardevice();
            midpointCircle(radius, color, a, b);
            radius--;
        }

        // Animate the circle growing
        while (radius <= 30) {
            delay(20);
            cleardevice();
            midpointCircle(radius, color, a, b);
            radius++;
        }
    }

    getch();
    closegraph();
    return 0;
}