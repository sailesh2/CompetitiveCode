class Solution {
private:
    int minTime(int index, vector<int>* tree, vector<bool>& apples, int* has){

        int totT=0;
        for(int i=0;i<tree[index].size();i++){
            int child = tree[index][i];
            if(has[child]==0){
                has[child]=1;

                int t = minTime(child, tree, apples, has);

                if(t==0){

                } else if(t==-1){
                    totT = totT + 2;
                }
                else{
                    totT = totT + 2 + t;
                }

            }
        }

        if(totT == 0){
            if(apples[index])
                totT=-1;
        }
        return totT;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        vector<int> tree[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        int has[100005]={0};
        has[0]=1;
        return minTime(0, tree, hasApple, has);
    }
};
