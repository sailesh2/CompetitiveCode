#include<bits/stdc++.h>

using namespace std;

vector<int> getDigits(long long int n){
    vector<int> dig;
    while(n>0){
        dig.push_back(n%3);
        n=n/3;
    }

    vector<int> rev;
    for(int i=dig.size()-1;i>=0;i--)
        rev.push_back(dig[i]);
    return rev;
}

long long int convertToNum(vector<int> dig){
    long long int v=0;
    for(int i=0;i<dig.size();i++){
        v=v*3+dig[i];
    }
    return v;
}

long long int nextGoodNumber(long long int n){
    vector<int> dig = getDigits(n);
    int save=-1;
    for(int i=0;i<dig.size();i++){
        if(dig[i]==2){
            save=i;
            break;
        }
    }

    if(save!=-1){
        int cnt=0;
        int save2;
        for(int i=save-1;i>=0;i--){
            if(dig[i]==0){
                dig[i]=1;
                cnt=1;
                save2=i;
                break;
            }
        }
        vector<int> nextDig;

        if(cnt==0){
            nextDig.push_back(1);
            for(int i=0;i<dig.size();i++){
                nextDig.push_back(0);
            }
        }else{

            for(int i=0;i<=save2;i++){
                nextDig.push_back(dig[i]);
            }
            for(int i=save2+1;i<dig.size();i++){
                nextDig.push_back(0);
            }
        }
        return convertToNum(nextDig);
    }else{
        return n;
    }
}

int main(){
    int q;
    long long int n;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>n;
        cout<<nextGoodNumber(n)<<"\n";
    }
    return 0;
}
