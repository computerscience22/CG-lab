#include <graphics.h>
#include <conio.h>
#include <stdio.h>

// Force Turbo C++ to link floating-point library
void linkfloat() {
    float a = 0, *b;
    b = &a;
    a = *b;
}

// Global variables for clipping window boundaries
float x_min, y_min, x_max, y_max;

int cliptest(float p, float q, float *t1, float *t2) {
    float r;
    int accept = 1;
    if (p < 0.0) {
        r = q / p;
        if (r > *t2)
            accept = 0;
        else if (r > *t1)
            *t1 = r;
    } else if (p > 0.0) {
        r = q / p;
        if (r < *t1)
            accept = 0;
        else if (r < *t2)
            *t2 = r;
    } else if (q < 0.0)
        accept = 0;
    return accept;
}

void liangBarsky(float x0, float y0, float x1, float y1) {
    float dx = x1 - x0, dy = y1 - y0;
    float t1 = 0.0, t2 = 1.0;
    if (cliptest(-dx, x0 - x_min, &t1, &t2))
        if (cliptest(dx, x_max - x0, &t1, &t2))
            if (cliptest(-dy, y0 - y_min, &t1, &t2))
                if (cliptest(dy, y_max - y0, &t1, &t2)) {
                    float nx0 = x0 + t1 * dx;
                    float ny0 = y0 + t1 * dy;
                    float nx1 = x0 + t2 * dx;
                    float ny1 = y0 + t2 * dy;

                    // Draw clipped line in RED
                    setcolor(RED);
                    line((int)nx0, (int)ny0, (int)nx1, (int)ny1);
                }
}

void drawClippingWindow() {
    setcolor(GREEN);
    rectangle((int)x_min, (int)y_min, (int)x_max, (int)y_max);
}

void main() {
    int gd = DETECT, gm;
    float x0, y0, x1, y1;

    linkfloat(); // Ensure floating-point support in Turbo C++

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Input clipping window coordinates
    printf("Enter clipping window coordinates (x_min y_min x_max y_max): ");
    scanf("%f%f%f%f", &x_min, &y_min, &x_max, &y_max);

    // Input original line coordinates
    printf("Enter x0 y0: ");
    scanf("%f%f", &x0, &y0);
    printf("Enter x1 y1: ");
    scanf("%f%f", &x1, &y1);

    cleardevice();
    drawClippingWindow();

    // Draw original line in WHITE
    setcolor(WHITE);
    line((int)x0, (int)y0, (int)x1, (int)y1);

    getch(); // Wait for keypress to show original line

    // Perform Liang-Barsky clipping and draw clipped line
    liangBarsky(x0, y0, x1, y1);

    getch(); // Wait for keypress to show clipped line
    closegraph();
}
