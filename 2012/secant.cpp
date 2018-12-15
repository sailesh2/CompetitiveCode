#include<stdio.h>
#include<conio.h>
#include<math.h>
void secant(float,float);
int cnt =1;
int main()
{
    printf("\nTHE FUNCTION IS=X^2-3");
    printf("\nLET a=1 and b=2");
    secant(1,2);
    getch();
    return 0;
}
void secant(float a,float b)
{
     
     float c=1;
     if(fabs(a-b)>=0.000001)
     {
     c=b-((pow(b,2)-3)*(b-a))/((pow(b,2)-3)-(pow(a,2)-3));
     printf("\niteration : %d root=%f",cnt,c);
     a=b;
     b=c;
     cnt++;
     secant(a,b);
     }
     else
     {
         printf("\ncomplete :-)");
         }
         }
         
     
     
    
