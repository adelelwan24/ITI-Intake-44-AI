#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#define null -32
#define size 3

 void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }


void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
//int main(){
//    textattr(0x03);
//    printf("\n hello");
//    textattr(0x07);
//    printf("\n hello");
//
//}

int main()
{
    char list[size][10] = {"new", "display", "exit"};
    short current=0;
    short flag=1;
    char input;

    do{
        system("cls");
        for (int i=0; i < size; i++)
        {
            if (current == i){
                textattr(0x70);
            }

            gotoxy(10, 3+ i);
            printf(list[i]);
            textattr(0x07);
        }
        input = getch();
        switch (input) {
            case -32:   //Extended key
                input = getch();
                switch (input) {
                    case 72:    //Up
                        current--;
                        if (current < 0)
                            current = size -1;
                        break;
                    case 80:    //Down
                        current++;
                        if (current > size -1)
                            current = 0;
                        break;
                    case 71:    //Home
                        current = 0;
                        break;
                    case 79:    //End
                        current = size -1;
                        break;
                }
                break;
            case 13:    //Enter
                system("cls");
                printf(list[current]);
                getch();
                break;
            case 27:    //ESC
                flag = 0;
                break;
        }
//        getch();
    } while (flag);

    return 0;
}
