class Solution {
private:
    int mp[300]={0};
    int grpCnt=0;
    vector<char> grps[500];

    set<pair<char,char>> df;
    set<pair<char,char>>::iterator dfIt;
    bool areSame(char a, char b){
             if(a=='a' && b=='e')
                 cout<<"enter"<<grps[mp[a]].size()<<" "<<grps[mp[b]].size();
        set<int> st;
        for(int i=0;i<grps[mp[a]].size();i++){
            for(int j=0;j<grps[mp[b]].size();j++){
                if(a=='a' && b=='e')
                cout<<grps[mp[a]][i]<<" "<<grps[mp[b]][j]<<"\n";
                if(df.count(make_pair(grps[mp[a]][i],grps[mp[b]][j]))>0)
                    return false;
            }
        }
        int c=mp[a];

        for(int i=0;i<grps[mp[a]].size();i++){
            grps[mp[b]].push_back(grps[mp[a]][i]);
        }
        for(int i=0;i<grps[mp[a]].size();i++){
            mp[grps[mp[a]][i]]=mp[b];

        }

        grps[c].clear();

        return true;

    }

    bool storeDiff(char a, char b){
        if(a==b)
            return false;
        df.insert(make_pair(a,b));
        df.insert(make_pair(b,a));
        int hashVA = mp[a];
        int hashVB = mp[b];

        if(hashVA == 0 && hashVB==0){
            mp[a]=++grpCnt;
            grps[grpCnt].push_back(a);
            mp[b]=++grpCnt;
            grps[grpCnt].push_back(b);
            return true;
        }else if(hashVA!=0 && hashVB!=0){
            return mp[a]!=mp[b];
        }else if(hashVA!=0){
            mp[b]=++grpCnt;
            grps[grpCnt].push_back(b);
            return true;
        }else{
            mp[a]=++grpCnt;
            grps[grpCnt].push_back(a);
            return true;
        }
    }


    bool storeSame(char a, char b){
        int hashVA = mp[a];
        int hashVB = mp[b];

        if(a=='a' && b=='e'){
            cout<<"hash-"<<hashVA<<" "<<hashVB<<"\n";
        }

        if(hashVA == 0 && hashVB==0){
            grpCnt++;
            mp[a]=grpCnt;
            mp[b]=grpCnt;
            grps[grpCnt].push_back(a);
            grps[grpCnt].push_back(b);
            return true;
        }else if(hashVA!=0 && hashVB!=0){
            return mp[a]==mp[b] || areSame(a,b);
        }else if(hashVA!=0){
            mp[b]=mp[a];
            grps[mp[a]].push_back(b);
            return true;
        }else{
            mp[a]=mp[b];
            grps[mp[b]].push_back(a);
            return true;
        }
    }

    bool process(string equation){
        char var1=equation[0];
        char op1=equation[1];
        char op2=equation[2];
        char var2=equation[3];

        if(op1=='!'){
            return storeDiff(var1,var2);
        }else{
            return storeSame(var1,var2);

        }

    }

    bool eqPossible(vector<string>& equations){

        for(int i=0;i<equations.size();i++){
            string eq = equations[i];
            if(!process(eq))
                return false;
        }
        return true;
    }
public:
    bool equationsPossible(vector<string>& equations) {
        return eqPossible(equations);
    }
};
