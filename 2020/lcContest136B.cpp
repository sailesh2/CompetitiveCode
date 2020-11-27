class Solution {
private:
    vector<int> graph[20005];
    vector<int> ans;

    void fillGraph(vector<vector<int>>& paths){
        for(int i=0;i<paths.size();i++){
            graph[paths[i][0]].push_back(paths[i][1]);
            graph[paths[i][1]].push_back(paths[i][0]);
        }
    }

    void fillEmptyGarden(int n){
        for(int i=0;i<=n;i++)
            ans.push_back(0);
    }

    bool isPossible(int gardenNo){
        int g=ans[gardenNo];
        for(int i=0;i<graph[gardenNo].size();i++){
            if(graph[gardenNo][i]==g)
                return false;
        }
        return true;
    }

    int missingFlower(set<int> flowers){
        for(int i=1;i<=4;i++){
            if(flowers.count(i)==0)
                return i;
        }
        return 0;
    }

    int getFlower(int gardenNo){
        if(ans[gardenNo]!=0 && isPossible(gardenNo))
            return ans[gardenNo];
        set<int> flowers;
        for(int i=0;i<graph[gardenNo].size();i++){
            flowers.insert(ans[graph[gardenNo][i]]);
        }
        return missingFlower(flowers);
    }

    vector<int> garden(int N){
        fillEmptyGarden(N);

        for(int i=1;i<=N;i++){
            ans[i]=getFlower(i);
        }

        vector<int> ans2;
        for(int i=1;i<=N;i++)
            ans2.push_back(ans[i]);
        return ans2;
    }
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        fillGraph(paths);
        return garden(N);
    }
};
