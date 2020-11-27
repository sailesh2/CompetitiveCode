class Solution {
private:
    map<string,int> dp;
    map<string,int>::iterator dpIt;
    int n,m;
    int MAX=1000000000;

    void flip(int x, int y, vector<vector<int>>& mat){
        mat[x][y]=1-mat[x][y];
        if(x-1>=0)
            mat[x-1][y]=1-mat[x-1][y];
        if(y-1>=0)
            mat[x][y-1]=1-mat[x][y-1];
        if(x+1<n)
            mat[x+1][y]=1-mat[x+1][y];
        if(y+1<m)
            mat[x][y+1]=1-mat[x][y+1];
    }

    string serialize(vector<vector<int>>& mat){
        string s="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                s.push_back((char)(mat[i][j]+48));
        }
        return s;
    }

    bool isAllZero(vector<vector<int>>& mat){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1)
                    return false;
            }
        }

        return true;
    }

    int minFlipsDP(vector<vector<int>>& mat, set<string> has){
        if(isAllZero(mat))
            return 0;

        string s=serialize(mat);
        if(has.count(s)>0){
            //dp.insert(make_pair(s,-1));
            return -1;
        }
        has.insert(s);
        int v;
        int mini=MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                flip(i,j,mat);
                string s2=serialize(mat);
                dpIt=dp.find(s2);
                if(dpIt==dp.end()){
                    v=minFlipsDP(mat,has);
                }else{
                    v=dpIt->second;
                }
                flip(i,j,mat);
                if(v!=-1){
                    mini=min(mini,v+1);
                }
            }
        }
        has.erase(has.find(s));
        if(mini==MAX)
            mini=-1;
        dp.insert(make_pair(s,mini));
        return mini;
    }
public:
    int minFlips(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        set<string> has;
        return minFlipsDP(mat,has);
    }
};
