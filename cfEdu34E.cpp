#include<bits/stdc++.h>

using namespace std;

int main(){
    int k,n;
    cin>>k>>n;
    string arr[k];
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    string s=arr[0],save;
    int cnt=1,ctr;
    char temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            s=arr[0];
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;

            cnt=0;
            for(int l=1;l<k;l++){
                ctr=0;
                for(int m=0;m<n;m++){
                    if(arr[l][m]!=s[m]){
                        ctr++;
                    }
                }
                if(ctr>2){
                    cnt=1;
                    break;
                }
            }
            if(cnt==0){
                save=s;
                break;
            }
        }
        if(cnt==0){
            break;
        }
    }

    if(cnt==0){
        cout<<save;
    }else{
        cout<<"-1";
    }
    return 0;
}
