#include<stdio.h>



int main()
{
   int t;
   long long int number;
   scanf("%d",&t);
   for (int i = 0; i < t; ++i)
    {
      scanf("%d",&number);
      long long int sum = 0;
      for ( int j = 1; j * j <= number; ++j )
      {
         if ( number % j == 0 ) {
            if(j%4!=0)
                sum += j;
            if((number/j)%4!=0)
                sum += number / j;
         }
         if ( j * j == number )
         {
             if(j%4!=0)
                sum -= j;
         }
      }
      printf("%lld\n",8*sum);
   }
   return 0;
}
