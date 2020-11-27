#include<bits/stdc++.h>

using namespace std;

bool plankComp(pair<int,int> a, pair<int,int> b){
    return a.first<b.first;
}

int main(){
    int n,m,d,p;
    cin>>n>>m>>d;
    int planks[m];
    for(int i=0;i<m;i++){
        cin>>p;
        planks[i]=p;
    }

    int ans[n];
    for(int i=0;i<n;i++)
        ans[i]=-1;
    int plankInd=0,cnt=0,s=0;
    for(int i=d-1;i<n;i=i+d){
        if(plankInd>=m){
            cnt=1;
            break;
        }
        p=planks[plankInd];
        if(i+p>n)
            break;
        for(int j=i;j<i+p;j++){
            ans[j]=plankInd;
        }
        i=i+p-1;
        if(i+d>=n){
            s=s-(n-i-1);
        }
        plankInd++;
    }

    if(cnt==1){
        cout<<"NO";
    }else{
        cout<<"YES\n";
        int ctr=0;
        for(int i=plankInd;i<m;i++){
            s=s+planks[i];
        }
        s=max(0,s);
        int pos=n,temp;
        for(int i=0;i<n;i++){
            if(ans[i]==-1){
                ctr=min(ctr+1,s);
            }else{
                temp=ans[i-ctr];
                ans[i-ctr]=ans[i];
                ans[i]=temp;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(ans[i]==-1){
                pos=i;
                break;
            }else
                break;
        }
        for(int i=pos;i<n;i++){
            if(plankInd>=m){
                break;
            }
            p=planks[plankInd];
            for(int j=i;j<i+p;j++){
                ans[j]=plankInd;
            }
            i=i+p-1;
            plankInd++;
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]+1<<" ";
        }
    }

    return 0;
}
