class Solution {
private:
    vector<int> graph[10000];
    int dependency[100000]={0};
    vector<int> nodes;

    bool canFinishTOPO(){
        int save;
        while(nodes.size()>0){
            save=-1;
            for(int i=0;i<nodes.size();i++){
                if(dependency[nodes[i]]==0){
                    save=i;
                    break;
                }
            }
            if(save!=-1){
                for(int j=0;j<graph[nodes[save]].size();j++){
                    dependency[graph[nodes[save]][j]]--;
                }
                nodes.erase(nodes.begin()+save);
            }else
                break;
        }
        return nodes.size()==0;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int ctr[100000]={0};
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
            if(ctr[prerequisites[i].first]==0){
                ctr[prerequisites[i].first]=1;
                nodes.push_back(prerequisites[i].first);
            }
            if(ctr[prerequisites[i].second]==0){
                ctr[prerequisites[i].second]=1;
                nodes.push_back(prerequisites[i].second);
            }
            dependency[prerequisites[i].first]++;
        }
        return canFinishTOPO();
    }
};
