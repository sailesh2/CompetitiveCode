#include<bits/stdc++.h>

using namespace std;

long long int calSum(vector<long long int> v){
    long long int s=0;
    for(long long int i=0;i<v.size();i++)
        s=s+v[i];
    return s;
}

int main(){
    long long int n,d,m;
    cin>>n>>d>>m;
    long long int x;
    vector<long long int> great,lesser;
    for(long long int i=0;i<n;i++){
        cin>>x;
        if(x>m){
            great.push_back(x);
        }else{
            lesser.push_back(x);
        }
    }
    long long int gs = great.size();
    if(gs==0){
        cout<<calSum(lesser);
    }else if(gs==1){
        lesser.push_back(great[0]);
        cout<<calSum(lesser);
    }else{
        vector<long long int> ans;

        sort(great.begin(),great.end());
        sort(lesser.begin(),lesser.end());
        long long int save=0;
        long long int pos=gs-1;
        for(long long int i=gs-1;i>=1;i--){
            ans.push_back(great[i]);
            if((save+d)>lesser.size()){
                break;
            }
            save=save+d;
            pos--;
        }

        if(pos==0){
            for(long long int i=save;i<lesser.size();i++)
                ans.push_back(lesser[i]);
            ans.push_back(great[0]);
        }else{
            long long int rem = lesser.size();
            rem = rem - save;
            rem = d-rem;
            long long int lp=rem-1;
            pos--;
            while(lp<pos){
                ans.push_back(great[pos]);
                lp=lp+d;
                pos--;
            }

        }
        cout<<calSum(ans);
    }
    return 0;
}
