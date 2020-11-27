#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,q;
    cin>>n;
    int money[n+1];
    for(int i=1;i<=n;i++){
        cin>>money[i];
    }
    cin>>q;
    int type,p,x;
    set<int> st;
    int minMoney=0;
    int save=q+1;
    int arr[q][3];
    for(int i=0;i<q;i++){
        cin>>type;
        if(type==1){
            cin>>p>>x;
            money[p]=x;
            st.insert(p);
            arr[i][0]=1;
            arr[i][1]=p;
            arr[i][2]=x;
        }else{
            cin>>x;
            if(x>minMoney){
                st.clear();
                minMoney=x;
                save=i;
            }else{
                for(int j=i-1;j>save;j--){
                    if(arr[j][0]==1 && money[arr[j][1]]<x){
                        money[arr[j][1]]=x;
                    }

                }
            }
            arr[i][0]=2;
            arr[i][1]=x;
        }
    }

    for(int i=1;i<=n;i++){
        if(st.count(i)==0 && money[i]<minMoney)
            money[i]=minMoney;
        cout<<money[i]<<" ";
    }
    return 0;
}
