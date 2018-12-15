// A Dynamic Programming based C++ program to find minimum
// number operations to convert str1 to str2
#include<bits/stdc++.h>
using namespace std;


class Solution {

public:
    int minimumDeleteSum(string s1, string s2) {
       int n=s1.length(),m=s2.length();
       int L[n+1][m+1];
       int i, j;
       string X=s1,Y=s2;
       for (i=0; i<=n; i++)
       {
         for (j=0; j<=m; j++)
         {
           if (i == 0 || j == 0)
             L[i][j] = 0;

           else if (X[i-1] == Y[j-1])
             L[i][j] = L[i-1][j-1] + 1;

           else
             L[i][j] = max(L[i-1][j], L[i][j-1]);
         }
       }

       int c=0;

        for(i=0;i<n;i++){
            c=c+X[i];
        }
        for(i=0;i<m;i++){
            c=c+Y[i];
        }

       i = n;
       j = m;
       while (i > 0 && j > 0)
       {
          if (X[i-1] == Y[j-1])
          {
             c=c-2*X[i-1];
              i--; j--;
          }
          else if (L[i-1][j] > L[i][j-1])
             i--;
          else if (L[i-1][j] < L[i][j-1])
             j--;
           else
           {
               if(X[i-1]>Y[j]){
                   i--;
               }else{
                   j--;
               }
           }
       }

        return c;


    }
};


// Driver program
int main()
{
    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDistDP(str1, str2, str1.length(), str2.length());

    return 0;
}
