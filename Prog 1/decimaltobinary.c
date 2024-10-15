#include <stdio.h>

int main()
{
    int remainder, binary = 0, base = 1, num;

    printf("Enter a number from decimal to binary: ");
    scanf("%d", &num);

    while (num > 0)
    {
        remainder = num % 2;
        binary += remainder * base;
        num /= 2;
        base *= 10;
    }
    printf("Decimal to binary: %d\n", binary);
    return 0;
}