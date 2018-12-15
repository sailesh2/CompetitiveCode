class Solution {
private:
    vector<int> graph[10000];
    int dependency[100000]={0};
    vector<int> nodes;

    pair<bool,vector<int> > courseSchedule(){
        int save;
        vector<int> schedule;
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
                schedule.push_back(nodes[save]);
                nodes.erase(nodes.begin()+save);
            }else{
                schedule.clear();
                break;
            }
        }
        bool possible=false;
        if(nodes.size()==0)
            possible=true;
        return make_pair(possible,schedule);
    }
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        pair<bool,vector<int> > res= courseSchedule();
        bool canFinish=res.first;
        vector<int> schedule=res.second;
        int done[100000]={0};
        if(canFinish){
            for(int i=0;i<schedule.size();i++){
                done[schedule[i]]=1;
            }
            for(int i=0;i<numCourses;i++){
                if(done[i]==0)
                    schedule.push_back(i);
            }
        }
        return schedule;
    }
};
