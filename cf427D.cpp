#include<bits/stdc++.h>
using namespace std;

//map<pair<int,int>,int> has;
int arr[5005]={0};
int has[5001][5001]={0};

void findKPalin(int i, int j){
    int ctr=0,k;
    arr[ctr]++;
    while(i<j){
        k=(i+j)/2;
        if((j-i)%2!=0){
            j=k;
        }else{
            j=k-1;
        }
        if(has[i][j]==1){
            ctr++;
            arr[ctr]++;
        }else{
            break;
        }
    }
}

int main(){
    string s;
    cin>>s;
    int j,k,ctr;
    for(int i=0;i<s.length();i++){
        j=i-1;
        k=i+1;
        has[i][i]=1;
        findKPalin(i,i);
        while(j>=0 && k<s.length()){
            if(s[j]!=s[k]){
                break;
            }

            has[j][k]=1;
            findKPalin(j,k);
            j--;
            k++;
        }

        if(i+1<s.length() && s[i]==s[i+1]){
            j=i-1;
            k=i+2;

            has[i][i+1]=1;
            findKPalin(i,i+1);
            while(j>=0 && k<s.length()){
                if(s[j]!=s[k]){
                    break;
                }
                has[j][k]=1;
                findKPalin(j,k);
                j--;
                k++;
            }
        }
    }


    for(int i=0;i<s.length();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
