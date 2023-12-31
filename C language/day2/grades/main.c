#include <stdio.h>
#include <stdlib.h>

int main()
{
    int grade;
    printf("Please enter your grade: ");
    scanf("%d", &grade);

    if (90 <= grade && grade <= 100)
        printf("Excellent");
    else if (80 <= grade && grade < 90)
        printf("Very Good");
    else if (70 <= grade && grade < 80)
        printf("Good");
    else if (60 <= grade && grade < 70)
        printf("Acceptable");
    else if (0 <= grade && grade < 60)
        printf("Fail");
    return 0;
}
