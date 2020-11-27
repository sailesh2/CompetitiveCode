#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> tree[100005];
int dsuTree[100005]={0};

int getDSUParent(int x){
    while(dsuTree[x]!=0){
        x=dsuTree[x];
    }
    return x;
}
void dsu(int x, int y){

    int c1=0;
    while(dsuTree[x]!=0){
        c1++;
        x=dsuTree[x];
    }
    int c2=0;
    while(dsuTree[y]!=0){
        c2++;
        y=dsuTree[y];
    }
    if(x!=y){
    if(c1>c2){
        dsuTree[y]=x;
    }else{
        dsuTree[x]=y;
    }
    }
}

void parse(int root, int* has){

        if(tree[root].size()==0){
            has[root]=1;
            for(int i=root+1;i<=n;i++){
                /*if(has[i]==0){
                    has[i]=1;
                    dsuTree[i]=root;
                }else*/{
                    dsu(root,i);
                }
            }
            return;
        }
        for(int i=0;i<tree[root].size();i++){
            if(i==0){

                if(tree[root][i]-root>1){
                    has[root]=1;
                    for(int j=root+1;j<tree[root][i];j++){
                        /*if(has[j]==0){
                            has[j]=1;
                            dsuTree[j]=root;
                            parse(j,has);
                        }else*/{
                            dsu(root,j);
                        }
                    }
                }
            }else{
                if(tree[root][i]-tree[root][i-1]>1){
                    has[root]=1;

                    for(int j=tree[root][i-1]+1;j<tree[root][i];j++){
                        /*if(has[j]==0){
                            has[j]=1;
                            dsuTree[j]=root;
                            parse(j,has);
                        }else*/{
                            dsu(root,j);
                        }
                    }
                }
            }
        }

         for(int i=tree[root][tree[root].size()-1]+1;i<=n;i++){

            /*if(has[i]==0){
                has[i]=1;
                dsuTree[i]=root;
                parse(i,has);
            }else*/{
                dsu(root,i);
            }
         }

         return;

}
int main(){
    int m,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        if(u<v){
            tree[u].push_back(v);
        }else{
            tree[v].push_back(u);
        }
    }
    int s=0;

    int has[100005]={0};
    int cnt=0,ctr=0;
    for(int i=1;i<=n;i++){
        sort(tree[i].begin(),tree[i].end());
    }

    for(int i=1;i<n;i++){
        //if(has[i]==0){
            parse(i,has);
        //}
    }
    set<int> st;
    for(int i=1;i<=n;i++){
        int p=getDSUParent(i);
        //cout<<p;
        if(st.count(p)==0){
            st.insert(p);
            ctr++;
        }
    }
    cout<<ctr-1;
    return 0;
}
