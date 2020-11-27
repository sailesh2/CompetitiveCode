#include<bits/stdc++.h>

#define gc getchar

using namespace std;


inline int lscan()
{
int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

int main(){
    int n,m;
    n=lscan();
    m=lscan();
    int odd1=0,odd2=0,even1=0,even2=0;
    int x;
    for(int i=0;i<n;i++){
    x=lscan();
        if(x%2==0)
            even1++;
        else
            odd1++;
    }

    for(int i=0;i<m;i++){
      x=lscan();
        if(x%2==0)
            even2++;
        else
            odd2++;
    }

    cout<<min(even1,odd2)+min(even2,odd1);
    return 0;
}
