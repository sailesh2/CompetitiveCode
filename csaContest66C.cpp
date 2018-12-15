#include<bits/stdc++.h>

using namespace std;
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

int main(){
    int n,t;
    cin>>n>>t;
    int quacks[n];
    for(int i=0;i<n;i++){
        cin>>quacks[i];
    }
    int ctr,save,maxi=0,p;
    long long int lcm=findlcm(quacks,n);
    for(int i=1;i*i<=lcm;i++){
        if(lcm%i==0 && i<=t){
            ctr=0;
            for(int j=0;j<n;j++){
                if(i%quacks[j]==0){
                    ctr++;
                }
            }
            if(ctr>maxi){
                maxi=ctr;
                save=i;
            }else if(ctr==maxi){
                if(i<save){
                    save=i;
                }
            }
        }
        p=lcm/i;
        if(lcm%p==0 && p<=t){
            ctr=0;
            for(int j=0;j<n;j++){
                if(p%quacks[j]==0){
                    ctr++;
                }
            }
            if(ctr>maxi){
                maxi=ctr;
                save=p;
            }else if(ctr==maxi){
                if(p<save){
                    save=p;
                }
            }
        }
    }
    cout<<maxi<<" "<<t/save;
    return 0;
}
