#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s,a,b;
    vector<string> v;

    for(int i =0;i<n;i++){
        cin>>s;
        v.push_back(s);
    }
    int si = v.at(0).length();
    int cnt2=0,sm=0,mini=1000000000;
    for(int i=0;i<n;i++){
        a = v.at(i);
        sm =0;
        cnt2=0;
        for(int j=0;j<n;j++){
            if(i!=j){
                cnt2=0;
                b = v.at(j);
                for(int k=0;k<si;k++){
                    if(b[k] == a[0]){
                        int cnt = 0;
                        for(int l=0,r=k;l<si;l++){
                            if(a[l]!=b[r]){
                                cnt = 1;
                                break;
                            }
                            r =(r+1)%si;
                        }
                        if(cnt == 0){
                            cnt2 = 1;
                            sm = sm +k;
                            break;
                        }
                    }
                }
                if(cnt2 == 0){
                    break;
                }
            }
        }
        if(cnt2==0)
            break;
        mini = min(mini,sm);
    }
    if(n==1){
        cout<<"0";
    } else if(cnt2==0){
        cout<<"-1";
    } else{
        cout<<mini;
    }
    return 0;
}
