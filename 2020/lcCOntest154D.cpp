class Solution {
private:
    set<pair<int,int> > edges;
    int visited[100005]={0};

    void mark(vector<int> path, int start){
        for(int i=path.size()-1;i>=0;i--){
            if(path[i]==start){
                break;
            }
            if(edges.count(make_pair(path[i],path[i-1]))>0)
                break;
            edges.insert(make_pair(path[i],path[i-1]));
            edges.insert(make_pair(path[i-1],path[i]));
        }
    }


    void markCycles(int root, vector<int>* graph, vector<int> parentV, int* has,int p){

//cout<<root<<"r\n";
        visited[root]=1;
        for(int i=0;i<graph[root].size();i++){
            int next=graph[root][i];
     //       cout<<next<<"n ";
            if(visited[next]==1){
                if(has[next]==1){
                    if(p!=next){
                       mark(parentV,next);
                       edges.insert(make_pair(root,next));
                       edges.insert(make_pair(next,root));
                    }
                }
            }else{
                has[next]=1;
                parentV.push_back(next);
                markCycles(next,graph,parentV,has,root);
                parentV.pop_back();
                has[next]=0;
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> graph[100005];

        for(int i=0;i<connections.size();i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int> parentV;

        int has[100005]={0};
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                has[i]=1;
                parentV.push_back(i);
                markCycles(i,graph,parentV,has,-1);
                parentV.pop_back();
                has[i]=0;
            }
        }
      //  cout<<"done";

        vector<vector<int> > ans;
        for(int i=0;i<connections.size();i++){
            pair<int,int> ed = make_pair(connections[i][0],connections[i][1]);
            vector<int> v2;
            v2.push_back(connections[i][0]);
            v2.push_back(connections[i][1]);

            if(edges.count(ed)==0){
                ans.push_back(v2);
            }
        }

        return ans;
    }
};
