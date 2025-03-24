#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

void drawPoints(int x, int y, int xCenter, int yCenter){
    // Draw the points in all 8 octants
    putpixel(xCenter + x, yCenter - y, 2); // Top-right
    putpixel(xCenter - x, yCenter - y, 3); // Top-left
    putpixel(xCenter + x, yCenter + y, 4); // Bottom-right
    putpixel(xCenter - x, yCenter + y, 5); // Bottom-left
    putpixel(xCenter + y, yCenter - x, 6); // Right-top
    putpixel(xCenter - y, yCenter - x, 7); // Left-top
    putpixel(xCenter + y, yCenter + x, 8); // Right-bottom
    putpixel(xCenter - y, yCenter + x, 9); // Left-bottom
}
void drawCircle(int xCenter, int yCenter, int radius)
{
    int x = radius, y = 0;
    int decision = 1 - radius;

    drawPoints(x, y, xCenter, yCenter);

    while (x > y)
    {
        y++;

        if (decision <= 0)
        {
            decision = decision + 2 * y + 1;
        }
        else
        {
            x--;
            decision = decision + 2 * y - 2 * x + 1;
        }

        if (x < y)
            break;

        drawPoints(x, y, xCenter, yCenter);
        delay(100);
    }
}

int main()
{
    int gd = DETECT, gm;
    int xCenter, yCenter, radius;

    initgraph(&gd, &gm, "C://turboc3/bgi");

    // Input circle center and radius
    printf("Enter the center of the circle (x, y): ");
    scanf("%d %d", &xCenter, &yCenter);
    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);

    // Draw the circle using the midpoint circle algorithm
    drawCircle(xCenter, yCenter, radius);

    // Wait for user input to close the graphics window
    getch();
    closegraph();

    return 0;
}
