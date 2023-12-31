#include <stdio.h>
#include <stdlib.h>


#include <Windows.h>
#define null -32
void gotoxy(int x,int y)
    {
        COORD coord={0,0};
        coord.X=x;
        coord.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    }

int main()
{
    int dim;

    printf("Please enter box Dimension: ");
    scanf("%d", &dim);

    int scale = 4;
    int center = dim / 2  +1;

    int x,y;

    for (int i=1 ; i <= dim*dim ; i++)
    {
        if ( i == 1)
        {
            y = 1;
            x = center;
            gotoxy(x*scale, y);
            printf("%d", i);
        }
        else if ( (i-1) % dim != 0)
        {
            if (x == 1)
                x = dim;
            else {
                x--;
            }

            if ( y == dim)
                y = 1;
            else
                y++;

            gotoxy(x*scale, y);
            printf("%d", i);
        }
        else if ( (i-1) % dim == 0)
        {
            if (x == 1)
                x = dim;
            else
                x--;

            if ( y == 1)
                y = dim;
            else {
                y--;
            }

            gotoxy(x*scale, y);
            printf("%d", i);
        }
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
    /*
    for (int i=0 ; i < dim ; i++)
    {
        for (int j=0 ; j < dim;)
    }
    */
    return 0;
}
