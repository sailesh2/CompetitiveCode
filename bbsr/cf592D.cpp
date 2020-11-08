#include<bits/stdc++.h>

using namespace std;
long long int n;

long long int c0[100005];
long long int c1[100005];
long long int c2[100005];
long long int nodeColors[100005];

long long int dp[100005][3][3];
vector<pair<long long int,long long int> > childColors[100005][3][3];

pair<long long int,long long int> paintTreeColor(long long int root,long long int color,long long int color1,long long int child,long long int* has,vector<long long int>* tree);
void clearDP(){
    for(long long int i=0;i<=n;i++){
        dp[i][0][0]=-1;
        dp[i][0][1]=-1;
        dp[i][0][2]=-1;

        dp[i][1][0]=-1;
        dp[i][1][1]=-1;
        dp[i][1][2]=-1;

        dp[i][2][0]=-1;
        dp[i][2][1]=-1;
        dp[i][2][2]=-1;
    }
}

long long int paintTree(long long int root, long long int color, long long int color1, long long int* has, vector<long long int>* tree){
    long long int v=0;
    vector<pair<long long int,long long int> > childCols;

    if(root==0){
        vector<long long int> chs;
        for(long long int i=0;i<tree[root].size();i++){
            long long int child = tree[root][i];

            if(has[child]==0){
                chs.push_back(child);
            }
        }

        if(chs.size()==2){
            if(color==0){
                has[chs[0]]=1;
                long long int v1=paintTree(chs[0],1,color,has,tree)+c1[chs[0]];
                has[chs[0]]=0;

                has[chs[1]]=1;
                long long int v2=paintTree(chs[1],2,color,has,tree)+c2[chs[1]];
                has[chs[1]]=0;

                has[chs[0]]=1;
                long long int v3=paintTree(chs[0],2,color,has,tree)+c2[chs[0]];
                has[chs[0]]=0;

                has[chs[1]]=1;
                long long int v4=paintTree(chs[1],1,color,has,tree)+c1[chs[1]];
                has[chs[1]]=0;

                if(v1+v2<v3+v4){
                    v=v+v1+v2;
                    childCols.push_back(make_pair(chs[0],1));
                    childCols.push_back(make_pair(chs[1],2));
                }else{
                    v=v+v3+v4;
                    childCols.push_back(make_pair(chs[0],2));
                    childCols.push_back(make_pair(chs[1],1));

                }
            }else if(color==1){

                has[chs[0]]=1;
                long long int v1=paintTree(chs[0],0,color,has,tree)+c0[chs[0]];
                has[chs[0]]=0;

                has[chs[1]]=1;
                long long int v2=paintTree(chs[1],2,color,has,tree)+c2[chs[1]];
                has[chs[1]]=0;

                has[chs[0]]=1;
                long long int v3=paintTree(chs[0],2,color,has,tree)+c2[chs[0]];
                has[chs[0]]=0;

                has[chs[1]]=1;
                long long int v4=paintTree(chs[1],0,color,has,tree)+c0[chs[1]];
                has[chs[1]]=0;

                if(v1+v2<v3+v4){
                    v=v+v1+v2;
                    childCols.push_back(make_pair(chs[0],0));
                    childCols.push_back(make_pair(chs[1],2));
                }else{
                    v=v+v3+v4;
                    childCols.push_back(make_pair(chs[0],2));
                    childCols.push_back(make_pair(chs[1],0));

                }
            }else{
                has[chs[0]]=1;
                long long int v1=paintTree(chs[0],0,color,has,tree)+c0[chs[0]];
                has[chs[0]]=0;

                has[chs[1]]=1;
                long long int v2=paintTree(chs[1],1,color,has,tree)+c1[chs[1]];
                has[chs[1]]=0;

                has[chs[0]]=1;
                long long int v3=paintTree(chs[0],1,color,has,tree)+c1[chs[0]];
                has[chs[0]]=0;

                has[chs[1]]=1;
                long long int v4=paintTree(chs[1],0,color,has,tree)+c0[chs[1]];
                has[chs[1]]=0;

                if(v1+v2<v3+v4){
                    v=v+v1+v2;
                    childCols.push_back(make_pair(chs[0],0));
                    childCols.push_back(make_pair(chs[1],1));
                }else{
                    v=v+v3+v4;
                    childCols.push_back(make_pair(chs[0],1));
                    childCols.push_back(make_pair(chs[1],0));

                }
            }
        }else if(chs.size()==1){
            for(long long int i=0;i<tree[root].size();i++){
                long long int child = tree[root][i];
                if(has[child]==0){
                    has[child]=1;
                        pair<long long int,long long int> pr = paintTreeColor(root,color,color1,child,has,tree);
                        v=v+pr.first;
                        childCols.push_back(make_pair(child,pr.second));


                    has[child]=0;
                }
            }
        }

    }else{
        for(long long int i=0;i<tree[root].size();i++){
            long long int child = tree[root][i];
            if(has[child]==0){
                has[child]=1;
                    pair<long long int,long long int> pr = paintTreeColor(root,color,color1,child,has,tree);
                    v=v+pr.first;
                    childCols.push_back(make_pair(child,pr.second));


                has[child]=0;
            }
        }
    }
    if(color1==-1)
        color1=0;
    dp[root][color][color1]=v;
    childColors[root][color][color1]=childCols;
    return v;
}

long long int getRemainingColor(long long int color, long long int color1){
    for(long long int i=0;i<=2;i++){
        if(i!=color && i!=color1)
            return i;
    }
}

pair<long long int,long long int> paintTreeColor(long long int root, long long int color,long long int color1, long long int child, long long int* has,vector<long long int>* tree){
    if(color1==-1){
        long long int v1,v2;
        long long int col1,col2;
        if(color==0){
            if(dp[child][1][color]==-1)
                v1=paintTree(child,1,color,has,tree);
            else
                v1=dp[child][1][color];
            v1=v1+c1[child];
            col1=1;

            if(dp[child][2][color]==-1)
                v2=paintTree(child,2,color,has,tree);
            else
                v2=dp[child][2][color];
            v2=v2+c2[child];
            col2=2;
        }else if(color==1){
            if(dp[child][0][color]==-1)
                v1=paintTree(child,0,color,has,tree);
            else
                v1=dp[child][0][color];
            v1=v1+c0[child];
            col1=0;

            if(dp[child][2][color]==-1)
                v2=paintTree(child,2,color,has,tree);
            else
                v2=dp[child][2][color];
            v2=v2+c2[child];
            col2=2;
        }else{
            if(dp[child][1][color]==-1)
                v1=paintTree(child,1,color,has,tree);
            else
                v1=dp[child][1][color];
            v1=v1+c1[child];
            col1=1;

            if(dp[child][0][color]==-1)
                v2=paintTree(child,0,color,has,tree);
            else
                v2=dp[child][0][color];
            v2=v2+c0[child];
            col2=0;
        }

        if(v1<v2)
            return make_pair(v1,col1);
        else
            return make_pair(v2,col2);
    }else{
        long long int remCol = getRemainingColor(color,color1);
        long long int v;
        if(dp[child][remCol][color]==-1)
            v=paintTree(child,remCol,color,has,tree);
        else
            v=dp[child][remCol][color];
        if(remCol==0)
            v=v+c0[child];
        else if(remCol==1)
            v=v+c1[child];
        else
            v=v+c2[child];
        return make_pair(v,remCol);
    }
}

void traverseColor(long long int root, long long int color,long long int color1, long long int* has){
    nodeColors[root]=color;
    for(int i=0;i<childColors[root][color][color1].size();i++){
        pair<long long int,long long int> childCol = childColors[root][color][color1][i];
        long long int child=childCol.first;
        long long int col=childCol.second;
        if(has[child]==0){
            has[child]=1;
            traverseColor(child,col,color,has);
            has[child]=0;
        }
    }
}

int main(){
    cin>>n;
    long long int has[n];
    long long int ctr[n];
    for(long long int i=0;i<n;i++){
        cin>>c0[i];
        has[i]=0;
        ctr[i]=0;
    }
    for(long long int i=0;i<n;i++){
        cin>>c1[i];
    }
    for(long long int i=0;i<n;i++){
        cin>>c2[i];
    }

    vector<long long int> tree[n+1];
    long long int u,v;
    long long int cnt=0;
    for(long long int i=0;i<n-1;i++){
        cin>>u>>v;
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
        ctr[u]++;
        ctr[v]++;
        if(ctr[u]>=3 || ctr[v]>=3){
            cnt=1;
        }
    }

    if(cnt==1){
        cout<<"-1";
    }else{
        clearDP();
        has[0]=1;
        long long int v1=paintTree(0,0,-1,has,tree)+c0[0];
        long long int v2=paintTree(0,1,-1,has,tree)+c1[0];
        long long int v3=paintTree(0,2,-1,has,tree)+c2[0];

        if(v1<=v2 && v1<=v3){
            traverseColor(0,0,0,has);
            cout<<v1<<"\n";
        }else if(v2<=v1 && v2<=v3){
            traverseColor(0,1,0,has);
            cout<<v2<<"\n";
        }else{
            traverseColor(0,2,0,has);
            cout<<v3<<"\n";
        }

        for(long long int i=0;i<n;i++){
            cout<<nodeColors[i]+1<<" ";
        }
    }
    return 0;
}
