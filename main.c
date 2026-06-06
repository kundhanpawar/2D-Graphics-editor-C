#include <stdio.h>
#define HEIGHT 20
#define WIDTH 40
char canvas[HEIGHT][WIDTH];
void initializeCanvas()
{
    int i, j;
    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            canvas[i][j] = '_';
        }
    }
}
void drawLine(int row, int startCol, int endCol)
{
    int j;
    for(j = startCol; j <= endCol; j++)
    {
        canvas[row][j] = '*';
    }
}
void drawRectangle(int row, int col, int height, int width)
{
    int i, j;
    for(j = col; j < col + width; j++)
    {
        canvas[row][j] = '*';
        canvas[row + height - 1][j] = '*';
    }
    for(i = row; i < row + height; i++)
    {
        canvas[i][col] = '*';
        canvas[i][col + width - 1] = '*';
    }
}
void drawTriangle(int row, int col, int height)
{
    int i, j;
    for(i = 0; i < height; i++)
    {
        for(j = 0; j <= i; j++)
        {
            canvas[row + i][col + j] = '*';
        }
    }
}
void displayCanvas()
{
    int i, j;
    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("===== 2D GRAPHICS EDITOR =====\n\n");
    initializeCanvas();
    drawLine(5, 10, 30);
    drawRectangle(10, 5, 5, 15);
    drawTriangle(2, 2, 6);
    displayCanvas();
    return 0;
}
