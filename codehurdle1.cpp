#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
   int t, number,m;
   cin >> t;
   for (int i = 0; i < t; ++i)
    {
      cin >> number>>m;
      int sum = 1;
      for ( int j = 2; j * j <= number; ++j ) {
         if ( number % j == 0 ) {
            sum += j;
            sum += number / j;
         }
         if ( j * j == number ) sum -= j; // recalculate twice
      }
      if(arr[sum%m]==1)
        cout<<"YES\n";
      else
        cout<<"NO\n";
   }
   return 0;
}
