#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159

void drawPoint(int x, int y, int color, char* label) {
    setcolor(color);
    circle(x, y, 2);  // Small circle as a point
    outtextxy(x + 5, y, label);
}

void main() {
    int gd = DETECT, gm;
    int x, y;          // Original point
    int tx, ty;        // Translation values
    float sx, sy;      // Scaling values
    float angle, rad;  // Rotation
    int xt, yt;        // Translated point
    int xs, ys;        // Scaled point
    int xr, yr;        // Rotated point

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Input original point
    printf("Enter coordinates of the point (x y): ");
    scanf("%d %d", &x, &y);

    // Draw original point
    drawPoint(x, y, WHITE, "Original");
    getch();
    cleardevice();

    // Input for translation
    printf("Enter translation values (tx ty): ");
    scanf("%d %d", &tx, &ty);

    xt = x + tx;
    yt = y + ty;

    drawPoint(xt, yt, GREEN, "Translated");
    getch();
    cleardevice();

    // Input for scaling
    printf("Enter scaling factors (sx sy): ");
    scanf("%f %f", &sx, &sy);

    xs = (int)(x * sx);
    ys = (int)(y * sy);

    drawPoint(xs, ys, CYAN, "Scaled");
    getch();
    cleardevice();

    // Input for rotation
    printf("Enter rotation angle (in degrees): ");
    scanf("%f", &angle);

    rad = angle * PI / 180.0;

    xr = (int)(x * cos(rad) - y * sin(rad));
    yr = (int)(x * sin(rad) + y * cos(rad));

    drawPoint(xr, yr, RED, "Rotated");
    getch();

    closegraph();
}
