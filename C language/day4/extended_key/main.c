#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input;
    printf("Enter key:");
    input = getch();

    if (input == -32){
        input = getch();
        printf("Extended key: %c -> %d", input, input);
    }
    else
        printf("Normal key: %c -> %d", input, input);
    return 0;
}
