
int ranks[300][27];
int n;
bool comp(char a , char b){
    for(int i=0;i<n;i++){
        if(ranks[(int)a][i]<ranks[(int)b][i])
            return true;
    }
    return a<b;
}

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<char> teams;

        for(int i=0;i<votes[0].length();i++){
            teams.push_back(votes[0][i]);
        }
        n=teams.size();

        for(int i=0;i<300;i++){
            for(int j=0;j<27;j++)
                ranks[i][j]=0;
        }

        for(int i=0;i<votes.size();i++){
            for(int j=0;j<votes[i].length();j++){
                ranks[(int)votes[i][j]][j]++;
            }
        }

        sort(teams.begin(),teams.end(),comp);
        string ans="";
        for(int i=0;i<n;i++)
            ans.push_back(teams[i]);
        return ans;
    }
int ranks[300][27];
int n;
bool comp(char a , char b){
    for(int i=0;i<n;i++){
        if(ranks[(int)a][i]>ranks[(int)b][i]){
            return true;
        }
        if(ranks[(int)a][i]<ranks[(int)b][i]){
            return false;
        }
    }
    return a<b;
}

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<char> teams;

        for(int i=0;i<votes[0].length();i++){
            teams.push_back(votes[0][i]);
        }
        n=teams.size();

        for(int i=0;i<300;i++){
            for(int j=0;j<27;j++)
                ranks[i][j]=0;
        }

        for(int i=0;i<votes.size();i++){
            for(int j=0;j<votes[i].length();j++){
                ranks[(int)votes[i][j]][j]++;
            }
        }

       // cout<<ranks[(int)'A'][0]<<"\n";
       // cout<<ranks[(int)'B'][0]<<"\n";
       // cout<<ranks[(int)'C'][0]<<"\n";

        sort(teams.begin(),teams.end(),comp);
        string ans="";
        for(int i=0;i<n;i++)
            ans.push_back(teams[i]);
        return ans;
    }
};
