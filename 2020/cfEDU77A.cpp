#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int t,c,sum;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>c>>sum;

        if(sum<=c){
            cout<<sum<<"\n";
        }else{
            long long int part=sum/c;
            long long int rem=sum%c;
            long long int arr[c];
            for(long long int j=0;j<c;j++)
                arr[j]=part;
            for(long long int j=0;j<rem;j++)
                arr[j]++;
            long long int s=0;
            for(long long int j=0;j<c;j++)
                s=s+arr[j]*arr[j];
            cout<<s<<"\n";
        }
    }
    return 0;
}
