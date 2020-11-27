#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> tree[100005];

bool check(int root, int* has){
        if(tree[root].size()==0){
            for(int i=root+1;i<=n;i++){
                if(has[i]==1)
                    return true;
                else{
                    if(check(i,has))
                        return true;
                    }
            }
            return false;
        }
        for(int i=0;i<tree[root].size();i++){
            if(i==0){
                if(tree[root][i]-root>1){
                    for(int j=root+1;j<tree[root][i];j++){
                        if(has[j]==1){
                            return true;
                        }else{
                            if(check(j,has))
                                return true;
                        }
                    }
                }
            }else{
                if(tree[root][i]-tree[root][i-1]>1){

                    for(int j=tree[root][i-1]+1;j<tree[root][i];j++){
                        if(has[j]==1){
                            return true;
                        }else{
                            if(check(j,has))
                                return true;
                        }
                    }
                }
            }
        }

         for(int i=tree[root][tree[root].size()-1]+1;i<=n;i++){
            if(has[i]==1){
                return true;
            }else{
                if(check(i,has))
                    return true;
            }
         }

         return false;

}

void parse(int root, int* has){

        if(tree[root].size()==0){
            has[root]=1;
            for(int i=root+1;i<=n;i++){
                if(has[i]==0){
                    has[i]=1;
                    parse(i,has);
                }
            }
            return;
        }
        for(int i=0;i<tree[root].size();i++){
            if(i==0){
                if(tree[root][i]-root>1){
                    has[root]=1;
                    for(int j=root+1;j<tree[root][i];j++){
                        if(has[j]==0){
                            has[j]=1;
                            parse(j,has);
                        }
                    }
                }
            }else{
                if(tree[root][i]-tree[root][i-1]>1){
                    has[root]=1;

                    for(int j=tree[root][i-1]+1;j<tree[root][i];j++){
                        if(has[j]==0){
                            has[j]=1;
                            parse(j,has);
                        }
                    }
                }
            }
        }

         for(int i=tree[root][tree[root].size()-1]+1;i<=n;i++){
            if(has[i]==0){
                has[i]=1;
                parse(i,has);
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


    int cnt=0,ctr=0;
    for(int i=1;i<=n;i++){
        sort(tree[i].begin(),tree[i].end());
    }

    int has[100005]={0};
    for(int i=1;i<=n;i++){
        if(has[i]==0){
            bool res = check(i,has);
            parse(i,has);
            if(has[i]==0)
                cnt++;
            else if(!res)
                ctr++;
        }
    }
    cout<<cnt+ctr-1;
    return 0;
}
