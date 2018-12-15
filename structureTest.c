#include<stdio.h>
#include<string.h>

struct emp
{
    char *n;
    int age;
};
int main()
{
    struct emp e1={"Dravid",10};
    struct emp e2=e1;
    e2.n="SA";
    printf("%s%s",e2.n,e1.n);
    return 0;
}
