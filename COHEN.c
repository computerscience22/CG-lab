#include <graphics.h>
#include <conio.h>
#include <stdio.h>

#define INSIDE 0 // 0000
#define LEFT   1 // 0001
#define RIGHT  2 // 0010
#define BOTTOM 4 // 0100
#define TOP    8 // 1000

int xmin, ymin, xmax, ymax;

// Function to compute region code for a point (x, y)
int computeCode(int x, int y) {
    int code = INSIDE;
    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;
    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;
    return code;
}

// Cohen-Sutherland clipping algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both endpoints inside: trivially accept
            accept = 1;
            break;
        } else if (code1 & code2) {
            // Both endpoints share an outside zone: trivially reject
            break;
        } else {
            // At least one endpoint is outside the window
            int code_out;
            int x, y;

            // Choose endpoint outside window
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find intersection point
            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (code_out & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            // Replace outside point with intersection point
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        setcolor(RED);
        line(x1, y1, x2, y2);
        outtextxy(10, 10, "Line after clipping (RED)");
    } else {
        outtextxy(10, 10, "Line is outside the window and rejected");
    }
}

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    printf("Enter xmin, ymin: ");
    scanf("%d%d", &xmin, &ymin);
    printf("Enter xmax, ymax: ");
    scanf("%d%d", &xmax, &ymax);
    printf("Enter x1, y1: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter x2, y2: ");
    scanf("%d%d", &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    rectangle(xmin, ymin, xmax, ymax);
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    outtextxy(10, 30, "Original Line (WHITE)");

    getch();
    cleardevice();
    rectangle(xmin, ymin, xmax, ymax);
    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
}
