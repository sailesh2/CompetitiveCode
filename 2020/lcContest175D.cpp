class Solution {
private:
    map<pair<int,string>, int> dp;
    map<pair<int,string>, int>::iterator dpIt;

    int n,r;
    vector<vector<char>> s;

    int cal(string next){
        int c=0;
        for(int i=0;i<r;i++){
            if(next[i]=='$')
                c++;
        }
        return c;
    }

    bool isEmpty(int index, string row){

        if(index-1>=0 && row[index-1]=='$')
            return false;
        if(index+1<r && row[index+1]=='$')
            return false;
        return true;
    }

    int permute(int index, int rowIndex, string row, string next){
        if(index==r){
            int ans=0;
            dpIt=dp.find(make_pair(rowIndex+1,next));
            if(dpIt==dp.end())
            ans= maxStudent(next,rowIndex+1) +cal(next);
            else{
                int v=dpIt->second;
                ans= v+cal(next);
            }
            return ans;
        }

        if(next[index]=='.' && (index==0 || next[index-1]!='$') && isEmpty(index,row)){
            next[index]='$';
            int v1=permute(index+1,rowIndex,row,next);
            next[index]='.';
            int v2=permute(index+1,rowIndex,row,next);
            return max(v1,v2);
        }else{
            return permute(index+1,rowIndex,row,next);
        }
    }

    int maxStudent(string row, int index){
        if(index==n)
            return 0;
        string next="";
        for(int i=0;i<r;i++){
            next.push_back(s[index][i]);

        }
        int ans=permute(0,index,row,next);
        dp.insert(make_pair(make_pair(index,row),ans));
        return ans;
    }
public:
    int maxStudents(vector<vector<char>>& seats) {
        string row="";
        s=seats;
        r=seats[0].size();
        n=seats.size();
        for(int i=0;i<r;i++)
            row.push_back('#');

        return maxStudent(row,0);
    }
};
