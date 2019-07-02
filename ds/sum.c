#include <stdio.h>

int main()
{
    int a;
    scanf("n = %d", &a);
    a = func(a);
    printf("sum id %d", a);
    return 0;
}

int func(int n)
{
    int i = 0, sum = 0;
    while (sum < n)
    {
        sum += ++i;
    }
    return i;
}
