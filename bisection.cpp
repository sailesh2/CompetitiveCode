#include<stdio.h>
#include<conio.h>
#include<math.h>
int cnt=0;
void bisection(float,float);
int main()
{
    printf("THE FUNCTION IS=X^2-3");
    printf("the initial condition is a=1 and b=2");
    bisection(1,2);
    getch();
    return 0;
}
void bisection(float a,float b)
{
     cnt++;
     float c;
     c=(a+b)/2;
     float f1,f2,f3;
     f1=pow(c,2)-3;
     f2=pow(a,2)-3;
     f3=pow(b,2)-3;
     if(fabs(a-b)>=0.000001)
     {
      
          if((f1*f2)<0)
             {
                  b=c;
             }
             else if((f1*f3)<0)
             {
             a=c;
             }
             else
             {
                 printf(" :-) :-) :-)");
     
             }
    printf("\niteration :%d root=%f",cnt,c);
    bisection(a,b);
     }
     else
     {
         printf("itz over :-)");
     }
 
}                      
