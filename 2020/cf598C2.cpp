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
        plankInd=0;
        while(plankInd<m){

            int k=0;
            for(int i=0;i<n;i++){
                if(k>plankInd){
                    break;
                }
                p=planks[k];
                for(int j=i;j<i+p;j++){
                    ans[j]=plankInd;
                }
                i=i+p-1;
                k++;
            }
        }



        for(int i=0;i<n;i++){
            cout<<ans[i]+1<<" ";
        }
    }

    return 0;
}
