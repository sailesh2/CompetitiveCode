#include<bits/stdc++.h>

using namespace std;
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int main(){
    int k1,k2,k3,v1,v2,lcm;
    int s;
    set<int> st;
    cin>>k1>>k2>>k3;
    if(k1==1 || k2==1 || k3==1){
        cout<<"YES";
    }else{
        if(k1!=2 && k2!=2 && k3!=2){
            if(k1==3 && k2==3 && k3==3)
                cout<<"YES";
            else
                cout<<"NO";
        }else{
            if(k1==2){
                v1=k2;
                v2=k3;
            }else if(k2==2){
                v1=k1;
                v2=k3;
            }else{
                v1=k1;
                v2=k2;
            }
            lcm=(v1*v2)/gcd(v1,v2);
            for(int i=1;i<=lcm;i=i+v1){
                st.insert(i);
            }
            int save=-1;
            for(int i=1;i<=lcm;i=i+2){
                if(st.count(i)==0){
                    save=i;
                    break;
                }
            }
            if(save==-1){
                cout<<"YES";
            }else{
                for(int i=save;i<=lcm;i=i+v2){
                    st.insert(i);
                }

                int cnt=0;
                for(int i=0;i<=lcm;i++){
                    if(i%2!=0 && st.count(i)==0){
                        cnt=1;
                        break;
                    }
                }
                if(cnt==0)
                    cout<<"YES";
                else
                    cout<<"NO";
                }
        }
    }
    return 0;
}
