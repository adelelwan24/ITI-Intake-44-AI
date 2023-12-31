#include <stdio.h>
#include <stdlib.h>

int main()
{
    char fname[10];
    printf("Enter first name: ");
    scanf("%s", fname);

    char lname[10];
    printf("Enter last name: ");
    scanf("%s", lname);

    char fullname[20];
    strcpy(fullname, fname);
    strcat(fullname, " ");
    strcat(fullname, lname);

    printf("%s", fullname);
    return 0;
}

