#include<bits/stdc++.h>

using namespace std;

bool isZCY(int num){
    string s="";
    int ctr=0;
    while(num>0){
        s=s+(char)(num%10+48);
        num=num/10;
        ctr++;
    }
    if(ctr%2!=0)
        return false;
    else{
        int cnt=0;
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                cnt=1;
                break;
            }
            i++;
            j--;
        }
        return cnt==0;
    }
}
int main(){
    int k,p;
    cin>>k>>p;
    int ctr=0;
    int sum=0;
    int start=10;
    int endI=99;
    while(1){
        for(int i=start;i<=endI;i++){
            if(isZCY(i)){
                ctr++;
                sum=(sum+i)%p;
                if(ctr==k)
                    break;
            }
        }
        if(ctr==k)
            break;
        start=start*100;
        endI=endI*100+99;
    }
    cout<<sum;
    return 0;
}
