#include <graphics.h>
#include <conio.h>
#include <cmath>

void drawDottedLine(int x1, int y1, int x2, int y2, int dotLength, int gapLength) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    float length = sqrt(dx * dx + dy * dy);
    float step = dotLength + gapLength;
    int numDots = length / step;
    for (int i = 0; i < numDots; i++) {
        int startX = x1 + i * (dx / numDots);
        int startY = y1 + i * (dy / numDots);
        int endX = startX + dotLength * dx / length;
        int endY = startY + dotLength * dy / length;
        line(startX, startY, endX, endY);
    }
}

void drawDashedLine(int x1, int y1, int x2, int y2, int dashLength, int gapLength) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    float length = sqrt(dx * dx + dy * dy);
    float step = dashLength + gapLength;
    int numDashes = length / step;
    for (int i = 0; i < numDashes; i++) {
        int startX = x1 + i * (dx / numDashes);
        int startY = y1 + i * (dy / numDashes);
        int endX = startX + dashLength * dx / length;
        int endY = startY + dashLength * dy / length;
        line(startX, startY, endX, endY);
    }
}

void drawThickLine(int x1, int y1, int x2, int y2, int thickness) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    for (int i = -thickness / 2; i <= thickness / 2; i++) {
        line(x1, y1 + i, x2, y2 + i);
    }
}

int main() {
    int gd, gm;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "");

    // Draw solid lines

    line(150, 250, 450, 250); // Just to display a normal line
    // Draw dotted line
    setcolor(YELLOW);
    drawDottedLine(150, 300, 450, 300, 1, 10); // Dot length 10, Gap length 10

    // Draw dashed line
    setcolor(GREEN);
    drawDashedLine(150, 350, 450, 350, 20, 10); // Dash length 20, Gap length 10

    // Draw thick line
    setcolor(BLUE);
    drawThickLine(150, 400, 450, 400, 10); // Thickness 10

    getch();
    closegraph();
    return 0;
}
