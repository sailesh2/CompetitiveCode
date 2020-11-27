class Solution {
private:
    vector<int> tree[100005];
    vector<int> time;

    void createTree(vector<int>& manager){
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1)
                tree[manager[i]].push_back(i);
        }
    }

    int maxMin(int root){

        int maxi=0;
        for(int i=0;i<tree[root].size();i++){
            int child = tree[root][i];
            maxi=max(maxi,maxMin(child));
        }

        return time[root]+maxi;
    }

public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        createTree(manager);
        time=informTime;
        return maxMin(headID);
    }
};
