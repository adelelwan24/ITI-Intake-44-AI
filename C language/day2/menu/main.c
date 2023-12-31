#include <stdio.h>

int main()
{
    char ch;
    int flag=1;

    do
    {
        system("cls");
        printf("\n New \n Display \n Exit \n\n");
        ch = getch();
        switch (ch)
        {
            case 'n':
                printf("New");
                break;
            case 'd':
                printf("Display");
                break;
            case 'e':
                printf("Exit");
                flag=0;
                break;
        }

        getch();

    } while (flag);
    return 0;
}
