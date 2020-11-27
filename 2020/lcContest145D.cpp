class Solution {
private:
    vector<string> rskills;
    map<string,int> peopleMap;
    map<string,int>::iterator peopleMapIt;
    map<string,int> mp;
    map<string,int>::iterator mpIt;

    int n;
    int minS=1000000000;
    vector<int> ans;

    string getNewCurrent(){
        string s="";
        for(int i=0;i<n;i++){
            s.push_back('0');
        }

        return s;
    }

    int getSkillPos(string skill){
        mpIt = mp.find(skill);
        return mpIt->second;
    }

    void generatePeopleMap(vector<string> skills,int ind,int* has,int pos){

        if(ind>=skills.size()){
            string s=getNewCurrent();
            for(int j=0;j<skills.size();j++){

                if(has[j]==1){
                    int pos = getSkillPos(skills[j]);
                    s[pos]='1';
                }
            }

                peopleMap.insert(make_pair(s,pos));
            return;
        }

        has[ind]=1;
        generatePeopleMap(skills, ind+1,has,pos);
        has[ind]=0;
        generatePeopleMap(skills,ind+1,has,pos);

    }

    void createPeopleMap(vector<vector<string> > peoples){

        for(int j=0;j<rskills.size();j++){
            mp.insert(make_pair(rskills[j],j));
        }

        for(int i=0;i<peoples.size();i++){
            int has[100005]={0};
            generatePeopleMap(peoples[i],0,has,i);
        }
    }

    int getPeopleIndex(string s,int ind){
        cout<<ind<<" ";
        peopleMapIt=peopleMap.find(s);
        if(peopleMapIt!=peopleMap.end()){
            return peopleMapIt->second;
        }
        if(ind>=s.length())
            return -1;
        if(s[ind]=='0')
        {
            s[ind]='1';
            int pos = getPeopleIndex(s,ind+1);
            if(pos!=-1)
                return pos;
            s[ind]='0';
        }
        return getPeopleIndex(s,ind+1);
    }

    void storePeople(vector<string> taken){

        vector<int> v;
        for(int i=0;i<taken.size();i++){
            if(isEmpty(taken[i]))
                continue;
            peopleMapIt=peopleMap.find(taken[i]);
            if(peopleMapIt==peopleMap.end()){
                return;
            }
            v.push_back(peopleMapIt->second);
        }

        set<int> st;
        vector<int> dist;
        for(int i=0;i<v.size();i++){
            if(st.count(v[i])==0){
                st.insert(v[i]);
                dist.push_back(v[i]);
            }
        }
        if(dist.size()<minS){
            minS=dist.size();
            ans=dist;
        }
    }

    bool isEmpty(string s){
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                return false;
            }
        }
        return true;
    }

    void smallestSufficentTeam(vector<string> taken, int* has){

        int cnt=0;
        for(int i=0;i<rskills.size();i++){
            if(has[i]==0){
                cnt=1;
                has[i]=1;

                taken[taken.size()-1][i]='1';
                smallestSufficentTeam(taken,has);
                taken[taken.size()-1][i]='0';

                string newCurrent = getNewCurrent();
                newCurrent[i]='1';
                taken.push_back(newCurrent);
                smallestSufficentTeam(taken,has);
                taken.pop_back();

                has[i]=0;
            }
        }

        if(cnt==0){
            storePeople(taken);
        }

    }
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n=req_skills.size();
        rskills=req_skills;

        createPeopleMap(people);

        vector<string> taken;

        string s=getNewCurrent();
        taken.push_back(s);
        int has[100005];
        smallestSufficentTeam(taken,has);

        return ans;
    }
};
