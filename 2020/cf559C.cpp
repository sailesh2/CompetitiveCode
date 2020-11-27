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
    int brr[n];
    int grr[m];
    long long int sb=0;
    int maxib=0;
    for(int i=0;i<n;i++){
        brr[i]=lscan();
        sb=sb+(long long int)brr[i];
        maxib=max(maxib,brr[i]);
    }
    int minig=1000000000;
    for(int i=0;i<m;i++){
        grr[i]=lscan();
        minig=min(minig,grr[i]);
    }

    sb=sb*m;

    if(maxib>minig){
        cout<<"-1";
    }else{
        sort(brr,brr+n);
        sort(grr,grr+m);

        for(int i=m-1;i>=0;i--){
            if(grr[i]==brr[n-1])
                break;
            if(i==0){
                sb=sb+grr[0]-brr[n-2];
            }else{
                sb=sb+grr[i]-brr[n-1];
            }
        }
        cout<<sb;
    }

    return 0;
}
