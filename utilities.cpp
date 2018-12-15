#include<bits/stdc++.h>

using namespace std;

int main(){
    return 0;
}

#include "C:\Users\srt\Desktop\utilities.h"

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>

#define gc getchar

long long int binSear(long long int cost){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<k && pc2[save+ctr]<=cost){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    if(save==-1)
        return -1;
    return p2[save];
}
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int findlcm(int brr[], int n)
{
    // Initialize result
    int ans = brr[0];


    // ans contains LCM of arr[0],..arr[i]
    // after i'th iteration,
    for (int i=1; i<n; i++)
        ans = ( ((brr[i]*ans)) /
                (gcd(brr[i], ans)) );

    return ans;
}

inline long int lscan()
{
long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}


std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}
