#include<bits/stdc++.h>

using namespace std;

long long int bin(long long int low, long long int high){
    long long int mid = (low+high)/2;
    if(low==mid)
        return high;

    string ans;
    cout<<"? "<<low<<" "<<mid<<"\n";
    fflush(stdout);
    cin>>ans;
    if(ans.compare("x")==0 || ans.compare("X")==0){
        return bin(low,mid);
    }else if(ans.compare("e")==0){
        return -1;
    }else{
        return bin(mid,high);
    }
}

long long int binSear(){
    long long int ctr=1;
    long long int save=0;
    long long int save2=0;
    long long int k=2000000001;
    string ans;
    while(save+ctr<k){

        cout<<"? "<<save2<<" "<<save+ctr<<"\n";
        fflush(stdout);
        cin>>ans;
        if(ans.compare("x")==0 || ans.compare("X")==0){
            break;
        }else if(ans.compare("e")==0){
            return -1;
        }
        save2=save+ctr;
        ctr=ctr*2;
    }

    return bin(save2,save+ctr);
}

int main(){
    string s;
    while(1){
        cin>>s;
        if(s.compare("start")==0){
            long long int v = binSear();
            if(v==-1)
                break;
            cout<<"! "<<v<<"\n";
            fflush(stdout);
        }else if(s.compare("mistake")==0){
            break;
        }else if(s.compare("end")==0){
            break;
        }
    }
    return 0;
}
