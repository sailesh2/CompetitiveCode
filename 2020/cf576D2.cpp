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
    int top=-1;
    pair<int,int> stack[q];
    for(int i=0;i<q;i++){
        cin>>type;
        if(type==1){
            cin>>p>>x;
            money[p]=x;
            arr[i][0]=1;
            arr[i][1]=p;
            arr[i][2]=x;
        }else{
            cin>>x;
            while(top>=0 && stack[top].first<=x){
                top--;
            }
            stack[++top]=make_pair(x,i);
            arr[i][0]=2;
            arr[i][1]=x;
        }
    }
    if(top>=0){
        for(int i=stack[top].second+1;i<q;i++){
            st.insert(arr[i][1]);
        }

        minMoney=stack[0].first;
    }



    for(int i=top;i>=0;i--){
        int prev=i-1>=0?stack[i-1].second+1:0;
        pair<int,int> el = stack[i];
        int x=el.first;
        for(int j=prev;j<el.second;j++){
            if(st.count(arr[j][1])==0){
                if(money[arr[j][1]]<x){
                    money[arr[j][1]]=x;
                }
                st.insert(arr[j][1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(st.count(i)==0 && money[i]<minMoney)
            money[i]=minMoney;
        cout<<money[i]<<" ";
    }
    return 0;
}
