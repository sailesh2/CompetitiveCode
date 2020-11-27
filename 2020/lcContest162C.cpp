class Solution {
private:
    int getParentDSU(int x, int* dsuTree){
        while(dsuTree[x]!=-1){
            x=dsuTree[x];
        }
        return x;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int islands[n][m];
        int ctr=0;
        int dsuTree[n*m];
        for(int i=0;i<n*m;i++){
                dsuTree[i]=-1;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    if(i-1>=0 && grid[i-1][j]==0 && j-1>=0 && grid[i][j-1]==0){
                        if(islands[i-1][j]==islands[i][j-1]){
                            islands[i][j]=islands[i-1][j];
                        }else{
                            islands[i][j]=islands[i-1][j];
                            dsuTree[islands[i][j-1]]=islands[i-1][j];
                        }
                    }
                    else if(i-1>=0 && grid[i-1][j]==0){
                        islands[i][j]=islands[i-1][j];
                    }
                    else if(j-1>=0 && grid[i][j-1]==0){
                        islands[i][j]=islands[i][j-1];
                    }else{
                        islands[i][j]=ctr++;
                    }
                }else{
                    islands[i][j]=-1;
                }
            }
        }

        if(ctr==0)
            return 0;

        int closedIslands[ctr][4];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(islands[i][j]!=-1){
                    islands[i][j]=getParentDSU(islands[i][j],dsuTree);
                }
            }
        }
        ctr=0;
        vector<int> st;
        int has[10005]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<islands[i][j]<<" ";
                if(islands[i][j]!=-1){
                    if(has[islands[i][j]]==0){
                        has[islands[i][j]]=1;
                        st.push_back(islands[i][j]);
                    }
                }
            }
            cout<<"\n";
        }
        ctr=st.size();
        if(ctr==0)
            return 0;

        for(int i=0;i<ctr;i++){
            int pos=st[i];
            closedIslands[pos][0]=n+1;
            closedIslands[pos][1]=-1;
            closedIslands[pos][2]=m+1;
            closedIslands[pos][3]=-1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(islands[i][j]!=-1){
                        closedIslands[islands[i][j]][0]=min(closedIslands[islands[i][j]][0],i);
                        closedIslands[islands[i][j]][1]=max(closedIslands[islands[i][j]][1],i);;
                        closedIslands[islands[i][j]][2]=min(closedIslands[islands[i][j]][2],j);;
                        closedIslands[islands[i][j]][3]=min(closedIslands[islands[i][j]][3],j);

                }
            }
        }

        int cl=0;
        for(int i=0;i<st.size();i++){
            int pos=st[i];
            if(closedIslands[pos][0]-1>=0 && closedIslands[pos][1]+1<n && closedIslands[pos][2]-1>=0 && closedIslands[pos][3]+1<m){
                cout<<pos<<"\n";
                cl++;
            }
        }

        return cl;
    }
};
