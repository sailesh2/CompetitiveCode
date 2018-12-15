#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<math.h>

#define gc getchar

#define pc putchar
using namespace std;

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

inline void lprint(long int a)
{
 int i=0;
char S[20];
while(a>0)
{
    S[i++]=a%10+'0';
a=a/10;
}
--i;
while(i>=0)
pc(S[i--]);
pc(' ');
}

int main(){
    int n;
    n=lscan();
    map<int,vector<int> > mp;
    map<int,vector<int> >::iterator mpIt;
    vector<int> v;
    int ind;
    int arr[n],crr[n];
    pair<int,int> brr[n];
    for(int i=0;i<n;i++){
        arr[i]=lscan();
    }
    for(int i=0;i<n;i++){
        brr[i].first=lscan();
        brr[i].second=i;
    }
    sort(arr,arr+n);

    sort(brr,brr+n);

    for(int i=0;i<n;i++){
        ind=brr[i].second;
        crr[ind]=arr[n-1-i];
    }

    for(int i=0;i<n;i++){
        lprint(crr[i]);
     }
    return 0;
}
