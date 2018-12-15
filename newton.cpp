#include<stdio.h>
#include<conio.h>
#include<math.h>
void newton(float);
int cnt=1;
int main()
{
    printf("\nthe function is x^2--3");
    printf("\nusing newtons method calculate root");
    printf("\nthe derivative of the function is 2*x");
    printf("\nassuming initial root is 2.5");
    newton(0.5);
    getch();
    return 0;
}
void newton(float p)
{
     float dev;
     float func;
     float xn;
     float fxn;
    dev=(2*p);
    func=(pow(p,2)-3);
    xn=p-(func/dev);
    fxn=(pow(xn,2)-3);
    if(fabs(func-fxn)>=0.000001)
    {
    printf("\niteration :%d   root+%f",cnt,xn);
    cnt++;
    newton(xn);
    }
     else
     {
         printf("complete :-)");
     }
}
                  
