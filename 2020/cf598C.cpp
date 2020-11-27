#include<bits/stdc++.h>

using namespace std;

bool plankComp(pair<int,int> a, pair<int,int> b){
    return a.first<b.first;
}

int main(){
    int n,m,d,p;
    cin>>n>>m>>d;
    pair<int,int> planks[m];
    for(int i=0;i<m;i++){
        cin>>p;
        planks[i]=make_pair(p,i);
    }

    sort(planks,planks+m,plankComp);
    int ans[n];
    for(int i=0;i<n;i++)
        ans[i]=-1;
    int plankInd=m-1,cnt=0;
    for(int i=d-1;i<n;i=i+d){
        if(plankInd<0){
            cnt=1;
            break;
        }
        p=planks[plankInd].first;
        if(i+p>n)
            break;
        for(int j=i;j<i+p;j++){
            ans[j]=planks[plankInd].second;
        }
        i=i+p-1;
        plankInd--;
    }

    if(cnt==1){
        cout<<"NO";
    }else{
        int s=0,ctr=0;
        for(int i=plankInd;i>=0;i--){
            s=s+planks[i].first;
        }
        int pos=n;
        for(int i=0;i<n;i++){
            if(ans[i]==-1){
                ctr=min(ctr+1,s);
            }else{
                pos=i;
                ans[i-ctr]=ans[i];
            }
        }
        for(int i=pos+1;i<n;i++){
            p=planks[plankInd].first;
            for(int j=i;j<i+p;j++){
                ans[j]=planks[plankInd].second;
            }
            plankInd--;
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]+1<<" ";
        }
    }

    return 0;
}
