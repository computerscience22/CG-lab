#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    int tx, ty;
    float sx, sy;
    float angle, rad;
    int xr1, yr1, xr2, yr2, xr3, yr3;

    // Initialize graphics
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // User input for triangle coordinates
    printf("Enter coordinates of triangle:\n");
    printf("x1 y1: "); scanf("%d %d", &x1, &y1);
    printf("x2 y2: "); scanf("%d %d", &x2, &y2);
    printf("x3 y3: "); scanf("%d %d", &x3, &y3);

    // Draw original triangle
    setcolor(WHITE);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    outtextxy(10, 10, "Original Triangle");
    getch();
    cleardevice();

    // Translation input
    printf("\nEnter translation (tx ty): ");
    scanf("%d %d", &tx, &ty);

    setcolor(GREEN);
    drawTriangle(x1 + tx, y1 + ty, x2 + tx, y2 + ty, x3 + tx, y3 + ty);
    outtextxy(10, 10, "Translated Triangle");
    getch();
    cleardevice();

    // Scaling input
    printf("\nEnter scaling factors (sx sy): ");
    scanf("%f %f", &sx, &sy);

    setcolor(CYAN);
    drawTriangle((int)(x1 * sx), (int)(y1 * sy),
                 (int)(x2 * sx), (int)(y2 * sy),
                 (int)(x3 * sx), (int)(y3 * sy));
    outtextxy(10, 10, "Scaled Triangle");
    getch();
    cleardevice();

    // Rotation input
    printf("\nEnter rotation angle (in degrees): ");
    scanf("%f", &angle);

    rad = angle * PI / 180.0;

    xr1 = (int)(x1 * cos(rad) - y1 * sin(rad));
    yr1 = (int)(x1 * sin(rad) + y1 * cos(rad));

    xr2 = (int)(x2 * cos(rad) - y2 * sin(rad));
    yr2 = (int)(x2 * sin(rad) + y2 * cos(rad));

    xr3 = (int)(x3 * cos(rad) - y3 * sin(rad));
    yr3 = (int)(x3 * sin(rad) + y3 * cos(rad));

    setcolor(RED);
    drawTriangle(xr1, yr1, xr2, yr2, xr3, yr3);
    outtextxy(10, 10, "Rotated Triangle (about origin)");
    getch();

    closegraph();
}
