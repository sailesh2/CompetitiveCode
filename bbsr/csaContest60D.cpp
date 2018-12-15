#include<bits/stdc++.h>

using namespace std;

int n,mini=100000,cntr=0,cntb=0;
long long int tsr=0,tsb=0;
vector<int> saver,saveb;
vector<int> v;
long long int red[50],blue[50];

void countCardsRed(int ind,int ctr,long long int sr,long long int sb){
    if(sr==tsb-sb){
        if(abs(n-2*ctr)<mini){
            mini=abs(n-2*ctr);
            saver=v;

            cntr=1;
        }
        return;
    }
    for(int i=ind;i<=n/2;i++){
        v.push_back(i);
        countCardsRed(i+1,ctr+1,sr+red[i],sb+blue[i]);
        v.pop_back();
    }
}

void countCardsBlue(int ind,int ctr,long long int sr,long long int sb){
    if(sb==tsr-sr){
        if(abs(n-2*ctr)<mini){
            mini=abs(n-2*ctr);
            saveb=v;

            cntb=1;
        }
        return;
    }
    for(int i=ind;i<=n/2;i++){
        v.push_back(i);
        countCardsBlue(i+1,ctr+1,sr+red[i],sb+blue[i]);
        v.pop_back();
    }
}

int main(){
    cin>>n;
    int ans[n];
    for(int i=0;i<n;i++){
        cin>>red[i]>>blue[i];
        tsr=tsr+red[i];
        tsb=tsb+blue[i];
    }
    countCardsRed(0,0,0,0);
    countCardsBlue(0,0,0,0);
    if(cntr==0 && cntb==0)
        cout<<"-1";
    else if(cntr==1 && cntb==1){
        if(saver.size()<saveb.size()){
            for(int i=0;i<n;i++){
                ans[i]=1;
            }
            for(int i=0;i<saver.size();i++){
                ans[saver[i]]=0;
            }

        }else{
            for(int i=0;i<n;i++){
                ans[i]=0;
            }
            for(int i=0;i<saveb.size();i++){
                ans[saveb[i]]=1;
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i];
        }
    }else if(cntr==1){
            for(int i=0;i<n;i++){
                ans[i]=1;
            }
            for(int i=0;i<saver.size();i++){
                ans[saver[i]]=0;
            }
            for(int i=0;i<n;i++){
            cout<<ans[i];
            }

    }else{
            for(int i=0;i<n;i++){
                ans[i]=0;
            }
            for(int i=0;i<saveb.size();i++){
                ans[saveb[i]]=1;
            }
            for(int i=0;i<n;i++){
            cout<<ans[i];
            }
    }
    return 0;
}
