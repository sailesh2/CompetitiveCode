#include<bits/stdc++.h>

using namespace std;


class Solution {
private:
    set<string> deads;
    set<string> pr;
    map<string,int> has;
    map<string,int>::iterator hasIt;
    int mini=100000000,g=0;
    char nextDig(char in){
        if(in=='9')
            return '0';
        else
            return (char)((int)in+1);
    }
    char prevDig(char in){
        if(in=='0')
            return '9';
        else
            return (char)((int)in-1);
    }
    int openLockBT(string curr,string target){
        cout<<++g<<"\n";
        int minC=10000000;
        if(curr.compare(target)==0){
            return 0;
        }
        if(deads.count(curr)>0)
            return minC;
        string next=curr;
        char c;
        for(int i=0;i<curr.size();i++){
            c=nextDig(curr[i]);
            next[i]=c;
            hasIt=has.find(next);
            if(hasIt==has.end()){
                if(pr.count(next)==0){
                    pr.insert(next);
                    minC=min(minC,openLockBT(next,target)+1);
                    //pr.erase(next);
                }

            }else{
                minC=min(minC,(hasIt->second)+1);
            }
            c=prevDig(curr[i]);
            next[i]=c;
            hasIt=has.find(next);

            if(hasIt==has.end()){
                if(pr.count(next)==0){
                    pr.insert(next);
                    minC=min(minC,openLockBT(next,target)+1);
                    //pr.erase(next);
                }
            }else{
                minC=min(minC,(hasIt->second)+1);
            }
            next[i]=curr[i];
        }
        has.insert(make_pair(curr,minC));
        return minC;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        for(int i=0;i<deadends.size();i++){
            deads.insert(deadends[i]);
        }
        pr.insert("0000");
        return openLockBT("0000",target);
        //return mini;
    }
};

int main(){
    vector<string> deadends;
    deadends.push_back("0201");
    deadends.push_back("0101");
    deadends.push_back("0102");
    deadends.push_back("1212");
    deadends.push_back("2002");
    string target="0202";
    Solution sol;
    sol.openLock(deadends,target);
}
