#include<bits/stdc++.h>

using namespace std;
int n,l,k;

bool canSwim(int* d, int tideHeight, int flip, int startIndex, int endIndex){

    for(int m=startIndex;m<=endIndex;m++){
        if(d[m]+tideHeight>l){
            return false;
        }

        if(tideHeight==k){
            flip=1;
        }
        if(tideHeight==0){
            flip=0;
        }

        if(flip==0)
            tideHeight++;
        else
            tideHeight--;
    }

    return true;
}

bool canSwim(int* d){
    vector<int> save;
    save.push_back(-1);
    for(int i=0;i<n;i++){
        if(d[i]>l){
            return false;
        }

        if(d[i]+k<=l){
            save.push_back(i);
        }else{
            int cnt=0;
            for(int j=0;j<save.size();j++){
                for(int tm=0;tm<=k;tm++){
                    if(canSwim(d,tm,0,save[j]+1,i) || canSwim(d,tm,1,save[j]+1,i)){
                        cnt=1;
                        break;
                    }
                }
                if(cnt==1)
                    break;
            }
            if(cnt==0)
                return false;
        }
    }

    return true;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k>>l;
        int d[n];
        for(int j=0;j<n;j++){
            cin>>d[j];
        }
        if(canSwim(d)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
