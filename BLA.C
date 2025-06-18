#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

void bresenham(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    int e2;
    while (1)
    {
        putpixel(x0, y0, WHITE);
        printf("(%d, %d)", x0, y0);
        delay(100);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
     if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}
int main()
{
    int gd = DETECT, gm;
    int x0, y0, x1, y1;
    initgraph(&gd, &gm, "C://turboc3/bgi");
    printf("Enter coordinates of the first point (x0 y0): ");
    scanf("%d %d", &x0, &y0);
    printf("Enter coordinates of the second point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    bresenham(x0, y0, x1, y1);
    getch();
    closegraph();
    return 0;
}
