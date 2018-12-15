#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    struct emp
    {
        float b;
    };
    struct emp e[10];
    for(int i=0;i < 10;i++)
    {
        scanf("%f",&e[i].b);
    }
    for(int i=0;i < 10;i++)
    {
        printf("%f  ",e[i].b);
    }
    float a;
    /*cin>>a;
    cout<<a<<"\n";
    cout<<a+a+a<<"\n";
    cout<<3*a<<"\n";*/

    scanf("%f",&a);
    printf("%f\n",a);
    printf("%f\n",a+a+a);
    printf("%f\n",3*a);
    return 0;
}
