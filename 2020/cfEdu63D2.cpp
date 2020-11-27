#include<bits/stdc++.h>

#define gc getchar

using namespace std;

inline long long int lscan()
{
long long int n=0,c=gc();
long long int neg=1;

if(c==45)
    neg=-1;
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return neg*n;
}

long long int posAns(long long int* arr,long long int n, long long int k){
    long long int maxi2=0;
    long long int s=0;
    long long int start=-1;
    long long int endi;
    for(long long int i=0;i<n;i++){
        s=s+arr[i];
        if(s<0){
            s=0;
        }
        maxi2=max(maxi2,s);
    }

    s=0;
    for(long long int i=0;i<n;i++){
        if(arr[i]>0 && start==-1){
            start=i;
        }
        s=s+arr[i];
        if(s<0){
            s=0;
            start=-1;
        }
        if(s==maxi2){
            endi=i;
            break;
        }
    }

    if(start!=-1){
        //    cout<<start<<" "<<endi;
        for(long long int i=start;i<=endi;i++){
            arr[i]=arr[i]*k;
        }
    }


    long long int ans=0,maxi=0;
    for(long long int i=0;i<n;i++){
        ans=ans+arr[i];
        //cout<<arr[i];
        ans=max(0LL,ans);
        maxi=max(maxi,ans);
    }

    return maxi;
}

long long int negAns(long long int* arr, long long int n,long long int k){
    long long int maxi=0,maxSe=0;
    long long int s=0,s2=0,se=0,sNeg=0;
    long long int dp[n+1];
    long long int smBack=0;
    long long int maxSmBack=0;
    long long int maxDp=0;
    long long int smFront=0;
    int cnt=0;

    for(long long int i=0;i<n;i++){
        dp[i]=-1;
        s=s+arr[i];
        s=max(0LL,s);
        s2=s2+arr[i];
        s2=max(0LL,s2);

        if(s<=maxSe){
            sNeg=sNeg+arr[i]*k;
            //cout<<maxSe<<" "<<sNeg<<"\n";
            if(maxSe+sNeg>s2){
                s2=maxSe+sNeg;
            }

        }else{
            sNeg=0;
                smBack=0;
                maxSmBack=0;
                smFront=0;
                cnt=0;
                maxDp=0;
                for(long long int j=i;j>=0;j--){
                    if(dp[j]>=0){
                        maxSmBack=max(smBack+smFront+dp[j],maxSmBack);
                        maxDp = max(smBack + smFront*k + dp[j],maxDp);
                        break;
                    }
                    if(arr[j]<0){
                        cnt=1;
                    }
                    if(cnt==1){
                        smBack=smBack+arr[j]*k;
                    }else{
                        smFront=smFront+arr[j];
                    }

                    maxSmBack=max(maxSmBack,smBack+smFront);
                    maxDp=max(maxDp,smBack+smFront*k);
                }

                if(maxSmBack>s2){
                    s2=maxSmBack;
                }

                dp[i]=maxDp;

        }

        maxSe=max(maxSe,s);
        maxi=max(maxi,s2);
    }


    maxi=max(maxi,s2);

    return maxi;

}
int main(){
    long long int n,k;
    n=lscan();
    k=lscan();
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        arr[i]=lscan();
    }

    if(k<=0){
        cout<<negAns(arr,n,k);
    }else{
        cout<<posAns(arr,n,k);
    }
    return 0;
}
