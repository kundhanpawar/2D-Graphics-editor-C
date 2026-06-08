#include <stdio.h>
#define HEIGHT 20
#define WIDTH 40
#define MAX_SHAPES 100
char canvas[HEIGHT][WIDTH];
typedef struct
{
    int id;
    int type;      // 1-Line 2-Rectangle 3-Triangle 4-Circle
    int row;
    int col;
    int p1;
    int p2;
    int active;
} Shape;
Shape shapes[MAX_SHAPES];
int shapeCount = 0;
int nextID = 1;
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
    if(row < 0 || row >= HEIGHT)
    return;
    if(startCol > endCol)
    {
        int temp = startCol;
        startCol = endCol;
        endCol = temp;
    }
    for(j = startCol; j <= endCol; j++)
    {
        if(j >= 0 && j < WIDTH)
        canvas[row][j] = '*';
    }
}
void drawRectangle(int row, int col, int height, int width)
{
    int i, j;
    for(j = col; j < col + width; j++)
    {
        if(row >= 0 && row < HEIGHT && j >= 0 && j < WIDTH)
        canvas[row][j] = '*';
        if(row + height - 1 >= 0 && row + height - 1 < HEIGHT && j >= 0 && j < WIDTH)
        canvas[row + height - 1][j]='*';
    }
    for(i = row; i < row + height; i++)
    {
        if(i >= 0 && i < HEIGHT && col >= 0 && col < WIDTH)
        canvas[i][col] = '*';
        if(i >= 0 && i < HEIGHT && col + width - 1 >= 0 && col + width - 1 < WIDTH)
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
            if(row + i >= 0 && row + i < HEIGHT && col + j >= 0 && col + j < WIDTH){
            canvas[row + i][col + j] = '*';
        }
        }
    }
}
void drawCircle(int centerRow, int centerCol, int radius)
{
    int row, col;
    for(row = 0; row < HEIGHT; row++)
    {
        for(col = 0; col < WIDTH; col++)
        {
            int dx = row - centerRow;
            int dy = col - centerCol;
            if(dx * dx + dy * dy <= radius * radius)
            {
                canvas[row][col] = '*';
            }
        }
    }
}
void redrawCanvas()
{
    int i;
    initializeCanvas();
    for(i = 0; i < shapeCount; i++)
    {
        if(shapes[i].active == 1)
        {
            switch(shapes[i].type)
            {
                case 1:
                    drawLine(
                        shapes[i].row,
                        shapes[i].col,
                        shapes[i].p1
                    );
                    break;
                case 2:
                    drawRectangle(
                        shapes[i].row,
                        shapes[i].col,
                        shapes[i].p1,
                        shapes[i].p2
                    );
                    break;
                case 3:
                    drawTriangle(
                        shapes[i].row,
                        shapes[i].col,
                        shapes[i].p1
                    );
                    break;
                case 4:
                    drawCircle(
                        shapes[i].row,
                        shapes[i].col,
                        shapes[i].p1
                    );
                    break;
            }
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
    drawCircle(10, 30, 4);
    displayCanvas();
    return 0;
}
