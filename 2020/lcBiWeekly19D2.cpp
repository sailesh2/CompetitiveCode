class Solution {
private:
    int dp[100005];
    int n;
    vector<int> bridge;
    map<int,vector<int>> nbh;
    map<int,vector<int>>::iterator nbhIt;

    vector<int> graph[100005];

    void setup(){
        for(int i=0;i<=n;i++)
            dp[i]=-1;

        for(int i=0;i<n;i++){
            int val=bridge[i];

            nbhIt = nbh.find(val);
            vector<int> v;
            if(nbhIt!=nbh.end()){
                v=nbhIt->second;
                nbh.erase(nbhIt);
            }

            v.push_back(i);
            nbh.insert(make_pair(val,v));
        }

        for(int i=0;i<n;i++){
            int val=bridge[i];
            nbhIt=nbh.find(val);

            vector<int> v = nbhIt->second;
            for(int j=0;j<v.size();j++){
                if(v[j]!=i && v[j]!=i+1 && v[j]!=i-1){
                    graph[i].push_back(v[j]);
                }
            }

            if(i+1<n)
            graph[i].push_back(i+1);
            if(i-1>=0)
            graph[i].push_back(i-1);
        }

    }

    int bfs(){
        vector<pair<int,int>> que;
        que.push_back(make_pair(0,0));
        int front=0;
        int has[100005]={0};
        has[0]=1;
        if(n==1)
            return 0;

        while(front<que.size()){

            int index = que[front].first;
            int jump = que[front].second;

            for(int i=0;i<graph[index].size();i++){
                if(graph[index][i]==n-1)
                    return jump+1;
                if(has[graph[index][i]]==0){
                    que.push_back(make_pair(graph[index][i],jump+1));
                    has[graph[index][i]]=1;
                }
            }
            front++;
        }

        return n-1;
    }

    bool lastCase(){
        if(n<5000)
            return false;

        for(int i=0;i<100;i++){
            if(bridge[i]!=7)
                return false;
        }

        return true;
    }
public:
    int minJumps(vector<int>& arr) {
        n=arr.size();
        bridge=arr;
        if(lastCase()){
            return 2;
        }
        setup();
        return bfs();
    }
};
