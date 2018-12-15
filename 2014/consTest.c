#include<stdio.h>

int main()
{
    static int i;
    const int j;
    printf("%d",fun(1));
    return 0;
}
int fun(int a)
{
    return (a++);
}
