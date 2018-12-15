#include<stdio.h>
#include<string.h>
struct test
{
    int n;
    char *c;
};
int main()
{
    struct test t;
    t.c="fd";
    t.n=10;
    struct test t2=t;
    t2.c="aasaa";
    t2.n++;
    printf("%d%d%s%s",t.n,t2.n,t.c,t2.c);
    char *c;
    c="saasaa";
    char *m="saasaa";
    //strcat(c,m);
    if(c==m)
        printf("ea");
    else
        printf("b ");
    int arr0[2]={1,2};
    int arr[2][2]={{1,2},{3,4}};
    int (*q)[2]=arr;
    int *a=arr0;
    int *p[2]={a,a+1};
    printf("%d%d",sizeof(c),sizeof(p));
    return 0;
}
