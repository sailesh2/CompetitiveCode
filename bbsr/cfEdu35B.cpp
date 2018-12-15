#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,a,b,p,r,rp,p2,r2,ans=0;
    cin>>n>>a>>b;
    for(int i=a;i>=1;i--){
        p=n/i;
        r=n%i;
        if(r>0)
            p=p+1;
        rp=n-p;
        if(rp>0){
            for(int j=b;j>=1;j--){
                p2=rp/j;
                r2=rp%j;
                if(r2>0)
                ans=max(ans,min(min(i,r),min(r2,j)));
                else
                ans=max(ans,min(min(i,r),j));
            }
        }else{
            ans=max(ans,min(i,b));
        }
    }

    for(int i=b;i>=1;i--){
        p=n/i;
        r=n%i;
        if(r>0)
            p=p+1;
        rp=n-p;
        if(rp>0){
            for(int j=a;j>=1;j--){
                p2=rp/j;
                r2=rp%j;
                if(r2>0)
                ans=max(ans,min(min(i,r),min(r2,j)));
                else
                ans=max(ans,min(min(i,r),j));
            }
        }else{
            ans=max(ans,min(i,a));
        }
    }
    cout<<ans;
    return 0;
}
