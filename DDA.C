#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <graphics.h> // For graphical output

// Macro to round a floating point number
#define ROUND(x) ((int)(x + 0.5))

void DDA(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int i = 0;

    // Calculate steps required for generating pixel points
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    // Calculate the increment in x and y for each step
    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    // Starting point
    float x = x1;
    float y = y1;

    // Drawing the line pixel by pixel
    for (; i <= steps; i++)
    {
	putpixel(ROUND(x), ROUND(y), WHITE); // Plot the pixel using the rounded values
	x += xIncrement;                     // Increment x
	y += yIncrement;                     // Increment y
    delay(1);
    }
}

int main()
{
    // Initialize graphics mode
    int x1, y1, x2, y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C://turboc3/bgi");


    // Get coordinates for the two endpoints of the line
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    // Call DDA function to draw the line
    DDA(x1, y1, x2, y2);

    // Wait for the user to press a key
    getch();

    // Close the graphics mode
    closegraph();

    return 0;
}
