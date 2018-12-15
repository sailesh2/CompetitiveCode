#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
   int t;
   long long int number;
   cin >> t;
   for (int i = 0; i < t; ++i)
    {
      cin >> number;
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
      cout<<8*sum<<"\n";
   }
   return 0;
}
