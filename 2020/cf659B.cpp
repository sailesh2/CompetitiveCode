#include<bits/stdc++.h>

using namespace std;
int n,l,k;

bool canSwim(int* d, int t, int cnt){
    for(int i=0;i<n;i++){
        if(d[i]>l){
            return false;
        }
        if(d[i]+t>l){
                int cnt2=-1;
                for(int j=t-1;j>=0;j--){
                    int cnt3=0;
                    int tb=j;
                    for(int m=i;m>=max(0,i-2*k);m--){
                        if(d[m]+tb>l){
                            cnt3=1;
                            break;
                        }
                        if(tb==0)
                            tb=k;
                        else
                            tb--;
                    }
                    if(cnt3==0){
                        cnt2=j;
                        break;
                    }
                }
                if(cnt2==-1)
                    return false;
                t=cnt2;

        }
        if(t==0)
            cnt=0;
        else if(t==k)
            cnt=1;


        if(cnt==0)
            t++;
        else
            t--;
    }

    return true;
}

bool possible(int* d){


    for(int tm=0;tm<=k;tm++){
        if(canSwim(d,tm,0) || canSwim(d,tm,1))
            return true;
    }

    return false;
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
        if(possible(d)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
