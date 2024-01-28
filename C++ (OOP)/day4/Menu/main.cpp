#include <iostream>
#include <conio.h>

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <Windows.h>
#define null -32
//#define size 5


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

struct emp {
    int id;
    char name[10];
    int age;
};

void printEmp(struct emp x);
struct emp scanEmp(struct emp x);
void initializeEmpList(struct emp* emps, int emp_size);
void newEmp(struct emp* emps, int emp_size);
void displayEmps(struct emp* emps, int emp_size);
void deleteEmpById(struct emp* emps, int emp_size);
void deleteEmpByName(struct emp* emps, int emp_size);
void exitMenue(short* flag, struct emp* emps);

class EmpList
{
public:
    struct emp* emps;
    int emp_size;
    EmpList()
    {
        emp_size = 5;
        emps = (struct emp*)malloc(emp_size * sizeof(struct emp));
        initializeEmpList(emps, emp_size);
    }
    EmpList(int _size)
    {
        emp_size = _size;
        emps = (struct emp*)malloc(emp_size * sizeof(struct emp));
        initializeEmpList(emps, emp_size);
    }
};

class Menu
{
    int size;
    int current;
    int xPos;
    int yPos;
    char list[5][20];
    int defColor;
    int highColor;
public:
    Menu(int dc= 0x07, int hc=0x37, int _xpos =10, int _ypos = 3)
    {
        defColor = dc;
        highColor = hc;
        xPos = _xpos;
        yPos = _ypos;
        size = 5;
        current = 0;
//        for (int i=0; i < size; i++)
//        {
//            scanf("%s", &list[i]);
//        }
        strcpy(list[0], "new");
        strcpy(list[1], "display");
        strcpy(list[2], "delete by id");
        strcpy(list[3], "delete by name");
        strcpy(list[4], "exit");
    }

public:
    void dispalyMenu(struct emp* emps, int emp_size)
    {
        short flag=1;
        char input;

        do{
            system("cls");
            for (int j=0; j < size; j++)
            {
                if (current == j){
                    textattr(highColor);
                }

                gotoxy(xPos, yPos + j);
                printf(list[j]);
                textattr(defColor);
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
                    // application logic
                    system("cls");
                    if ( !strcmp(list[current], "new"))
                        newEmp(emps, emp_size);
                    else if ( !strcmp(list[current], "display"))
                        displayEmps(emps, emp_size);
                    else if ( !strcmp(list[current], "delete by id"))
                        deleteEmpById(emps, emp_size);
                    else if ( !strcmp(list[current], "delete by name"))
                        deleteEmpByName(emps, emp_size);
                    else if ( !strcmp(list[current], "exit"))
                        exitMenue(&flag, emps);
                    getch();
                    break;
                case 27:    //ESC
    //                flag = 0;
    //                free(emps);
                    exitMenue(&flag, emps);
                    break;
            }
        } while (flag);

    }
};

int main()
{
//    char list[size][20] = {"new", "display", "delete by id", "delete by name", "exit"};
//    short current=0

    // Dynamically allocate array of struct emp
    int emp_size;
    printf("Enter number of employees:");
    scanf("%d", &emp_size);

//    struct emp* emps = (struct emp*)malloc(emp_size * sizeof(struct emp));
    EmpList emps(emp_size);
    Menu menu;

    menu.dispalyMenu(emps.emps, emps.emp_size);
    // initialize the employees ids with -1
//    initializeEmpList(emps, emp_size);

    return 0;
}

void printEmp(struct emp x)
{
    printf("%d : %s : %d\n", x.id, x.name, x.age);
}
struct emp scanEmp(struct emp x)
{
    printf("Enter employee id:");
    scanf("%d", &x.id);
    printf("Enter employee name:");
    scanf("%s", x.name);
    printf("Enter employee age:");
    scanf("%d", &x.age);
    return x;
}
void initializeEmpList(struct emp* emps, int emp_size)
{
    for (int i=0; i < emp_size; i++)
        emps[i].id = -1;
}
void newEmp(struct emp* emps, int emp_size)
{
    int index;
    printf("Where to add the employee: ");
    scanf("%d", &index);
    if (index > emp_size)
        printf("Enter number less than %d", emp_size);
    else if (emps[index].id == -1)
        emps[index] = scanEmp(emps[index]);
    else
    {
        int owFlag;
        printf("overwirte? Enter 0 for no & 1 for yes:");
        scanf("%d", &owFlag);
        if (owFlag)
            {
                emps[index] = scanEmp(emps[index]);
                printf("Data has been overwrited successfully.");
            }
    }
}

void displayEmps(struct emp* emps, int emp_size)
{
    for (int i=0; i < emp_size; i++)
    {
        if (emps[i].id != -1)
            printEmp(emps[i]);
    }
}
void deleteEmpById(struct emp* emps, int emp_size)
{
    int delId;
    printf("Enter employee id:");
    scanf("%d", &delId);
    for (int i=0; i < emp_size; i++)
        {
            if(emps[i].id == delId)
                emps[i].id = -1;
        }
}
void deleteEmpByName(struct emp* emps, int emp_size)
{
    char delName[10];
    printf("Enter employee name:");
    scanf("%s", delName);
    for (int i=0; i < emp_size; i++)
        {
            if(!strcmp(emps[i].name, delName))
                emps[i].id = -1;
        }
}
void exitMenue(short* flag, struct emp* emps)
{
    *flag = 0;
    free(emps);
}
