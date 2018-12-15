class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int grp[100000]={0};
        int a,b,cnt=0;
        for(int i=0;i<graph.size();i++){
            a=grp[i];
            b=0;
            cnt=0;
            for(int j=0;j<graph[i].size();j++){
                if(grp[graph[i][j]]!=0){
                    b=grp[graph[i][j]];
                    break;
                }
            }
            if(a==0 && b==0){
                a=1;
                grp[i]=a;
                b=2;
                for(int j=0;j<graph[i].size();j++){
                    grp[graph[i][j]]=b;
                }
            }else if(a==0){
                if(b==1)
                    a=2;
                else
                    a=1;
                grp[i]=a;
                for(int j=0;j<graph[i].size();j++){
                    if(grp[graph[i][j]]==a){
                        cnt=1;
                        break;
                    }
                    grp[graph[i][j]]=b;
                }
            }else if(b==0){
                if(a==1)
                    b=2;
                else
                    b=1;
                for(int j=0;j<graph[i].size();j++){
                    grp[graph[i][j]]=b;
                }
            }else{
                if(a==b){
                    cnt=1;
                }else{
                    for(int j=0;j<graph[i].size();j++){
                        if(grp[graph[i][j]]==a){
                            cnt=1;
                            break;
                        }
                        grp[graph[i][j]]=b;
                    }
                }
            }
            if(cnt==1)
                break;
        }
        return cnt==0;
    }
};
