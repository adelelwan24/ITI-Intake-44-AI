#include <stdio.h>
#include <stdlib.h>


unsigned long factorial(long num);

int main()
{
    long num;
    printf("please enter a number: ");
    scanf("%ld", &num);

    unsigned long total;
    total = factorial(num);
    printf("Factorial is %ld", (unsigned long)total);


    return 0;
}

unsigned long factorial(long num)
{
    unsigned long total=1;

    if (num == 0 || num == 1)
        printf("Factorial is 1");
    else {
            for (int i=2; i <= num; i++)
            {
                total*=i;
                printf("%ld\n", total);
            }
        }
        printf("\n%ld\n %d\n", total, sizeof(long));
        return total;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <float.h>
//
//int main(int argc, char** argv) {
//
//    printf("CHAR_BIT    :   %d\n", CHAR_BIT);
//    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
//    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
//    printf("INT_MAX     :   %d\n", INT_MAX);
//    printf("INT_MIN     :   %d\n", INT_MIN);
//    printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
//    printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
//    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
//    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
//    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
//    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
//    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
//    printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);
//    printf("ULONG_MAX   :   %lu\n", (unsigned long) ULONG_MAX);
//    printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);
//
//    return 0;
//}
