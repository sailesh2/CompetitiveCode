#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<math.h>

using namespace std;
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
long long int findlcm(int brr[], int n)
{
    // Initialize result
    long long int ans = brr[0];

    // ans contains LCM of arr[0],..arr[i]
    // after i'th iteration,
    for (int i=1; i<n; i++)
        ans = ( ((brr[i]*ans)) /
                (gcd(brr[i], ans)) );

    return ans;
}
int arr[200];
int traverse(int,int,int);
int main(){
    int n,a;
    cin>>n;
    int in[200]={0},out[200]={0};
    for(int i=0;i<n;i++){
        cin>>a;
        arr[i+1]=a;
        out[i+1]++;
        in[a]++;
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        if(in[i]!=out[i]){
            cnt=1;
            break;
        }
    }
    int ans[n+1];
    long long int lcm,gcd2=0,p;
    if(cnt==1){
        cout<<"-1";
    } else{
        for(int i=1;i<=n;i++){
            ans[i-1]=traverse(i,i,0);
        }
        cout<<findlcm(ans,n);
        /*p=ans[1];
        lcm=ans[1];
        for(int i=1;i<=n;i++){
            p=ans[i]*lcm;
            gcd2=gcd(ans[i],gcd2);
            cout<<gcd2<<" ";
            lcm=p/gcd2;
            cout<<lcm<<" ";
        }
        cout<<lcm;*/
    }

    return 0;
}


int traverse(int ind,int start,int ctr){

    if(arr[ind]==start){
        ctr++;
        ctr = ctr%2==0?ctr/2:ctr;
        return ctr;
    }

    return traverse(arr[ind],start,ctr+1);
}
