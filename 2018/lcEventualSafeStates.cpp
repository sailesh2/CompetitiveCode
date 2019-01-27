class Solution {
private:
    map<int,int> nodeSafeStatus;

    bool insertNodeStatusSafe(int root){
        nodeSafeStatus.insert(make_pair(root,0));
        return true;
    }

    bool insertNodeStatusUnSafe(int root){
        nodeSafeStatus.insert(make_pair(root,1));
        return false;
    }

    bool isNodeStatusAvailable(int root){
        return nodeSafeStatus.find(root)!=nodeSafeStatus.end();
    }

    bool getNodeStatus(int root){
        return (nodeSafeStatus.find(root))->second == 0;
    }

    bool checkSafe(int root, vector<vector<int>>& graph, set<int>& visited){
        if(isNodeStatusAvailable(root)){
            return getNodeStatus(root);
        }

        if(visited.count(root)>0){
            return insertNodeStatusUnSafe(root);
        }

        visited.insert(root);
        for(int i=0;i<graph[root].size();i++){
            if(!checkSafe(graph[root][i],graph,visited)){
                return insertNodeStatusUnSafe(root);
            }
        }

        visited.erase(visited.find(root));
        return insertNodeStatusSafe(root);
    }

    vector<int> checkSafe(vector<vector<int>>& graph){
        vector<int> safeNodes;
        set<int> visited;

        for(int i=0;i<graph.size();i++){
            checkSafe(i,graph,visited);
        }

        for(int i=0;i<graph.size();i++){
            if(getNodeStatus(i))
                safeNodes.push_back(i);
        }

        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        return checkSafe(graph);
    }
};
