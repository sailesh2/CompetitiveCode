#include<bits/stdc++.h>

using namespace std;
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int brr[n];
    int cnt=0;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>brr[i];
        if(arr[i]==0 && brr[i]==0){

        }else{
            if(arr[i]-brr[i]<=0){
                cnt=1;
            }
            else if(arr[i]%(arr[i]-brr[i])!=brr[i]){
                cnt=1;
            }else{
                v.push_back(arr[i]-brr[i]);
            }
        }
    }
    if(cnt==1){
        cout<<"-1";
    }else{
        if(v.size()==0){
            cout<<"1";
        }else{
            int g=v[0];
            for(int i=1;i<v.size();i++){
                g=gcd(g,v[i]);
            }

            for(int i=0;i<n;i++){
                if(arr[i]%g!=brr[i]){
                    cnt=1;
                    break;
                }
            }
            if(cnt==0){
                int cnt3=0;
                int save=g;
                for(int l=1;l*l<=g;l++){
                    cnt3=0;
                    //if(g%l==0){
                        for(int i=0;i<n;i++){
                            if(arr[i]%l!=brr[i]){
                                cnt3=1;
                                break;
                            }
                        }

                        if(cnt3==0){
                            save=l;
                            break;
                        }
                    //}
                }
                cout<<save;
            }
            else
            cout<<"-1";

        }
    }
    return 0;
}
