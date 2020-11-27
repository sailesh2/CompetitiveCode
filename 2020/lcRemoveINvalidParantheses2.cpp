class Solution {
private:
    vector<string> finals;

    bool isValid(string s){
        int ctr=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                ctr++;
            else if(s[i]==')')
                ctr--;
            if(ctr<0)
                return false;
        }

        return ctr==0;
    }

    vector<string> distinct(vector<string> strings){
        set<string> st;
        vector<string> dis;

        for(int i=0;i<strings.size();i++){
            if(isValid(strings[i])){
                if(st.count(strings[i])==0){
                    dis.push_back(strings[i]);
                    st.insert(strings[i]);
                }
            }
        }

        return dis;
    }

    int findMaxLen(){
        int maxi=0;
        for(int i=0;i<finals.size();i++){
            maxi=max(maxi,finals[i].length());
        }
        return maxi;
    }

    vector<string> takeMaxFinals(int l){
        vector<string> v;
        for(int i=0;i<finals.size();i++){
            if(finals[i].length()==l)
                v.push_back(finals[i]);
        }
        return v;
    }

    void filter(){
        finals = distinct(finals);
        int maxL = findMaxLen();
        finals = takeMaxFinals(maxL);
    }

    void removeParan(string s, int start, int* has){
        int last=0;
        for(int i=start;i<s.length();i++){
            if(s[i]=='(' || s[i]==')'){
                last=1;
                has[i]=1;
                removeParan(s, i+1, has);
                has[i]=0;

                generateAllStrings(s, i+1, has);
                break;
            }
        }

        string finalStr="";
        if(last==0){
            for(int i=0;i<s.length();i++){
                if(has[i]==0){
                    finalStr.push_back(s[i]);
                }
            }
            if(isValid(finalStr)){
                cout<<finalStr<<"\n";
                finals.push_back(finalStr);
            }
            filter();
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int has[100005]={0};
        removeParan(s,0,has);
        return finals;
    }
};
