#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {

        vector<string> curr;
        end = endWord;
        list = wordList;
        if(count(wordList.begin(),wordList.end(),end)==0)
            return res;
        curr.push_back(beginWord);
        return find(beginWord,curr);
    }
private:
    string end;
    vector<vector<string> > res;
    vector<string> list;
    map<string,vector<vector<string> > > dp;
    map<string,vector<vector<string> > >::iterator dpIt;

    vector<vector<string> > find(string begin,vector<string> curr) {
        vector<vector<string> > ans,ans1;
        vector<string> ansS;
        if(begin.compare(end)==0){
            ansS.push_back(begin);
            ans.push_back(ansS);
            return ans;
        }

        string s=begin;
        int size,mini=1000000000;
        for(int i=0;i<s.size();i++) {
            for(int j='a';j<='z';j++){
                s.at(i)=(char)j;
                if(count(list.begin(),list.end(),s)!=0 && count(curr.begin(),curr.end(),s)==0){
                    //cout<<s<<"\n";
                    dpIt=dp.find(s);
                    if(dpIt==dp.end()) {
                        curr.push_back(s);
                        ans1 = find(s,curr);
                        curr.pop_back();
                    } else {
                        ans1 = dpIt->second;
                    }

                    if(ans1.size()>0 && ans1.at(0).size()+1<mini){
                            mini = ans1.at(0).size()+1;
                            ans = ans1;
                    } else if(ans1.size()>0 && ans1.at(0).size()+1 == mini){
                        for(int k=0;k<ans1.size();k++){
                            ans.push_back(ans1.at(k));
                        }
                    }

                    /*for(int k=0;k<ans1.size();k++){
                        for(int l=0;l<ans1.at(k).size();l++)
                            cout<<ans1.at(k).at(l)<<" ";
                        cout<<"\n";
                    }*/
                }
                s=begin;
            }
        }
        for(int i=0;i<ans.size();i++){
            ans.at(i).insert(ans.at(i).begin(),begin);
        }
        if(ans.size()>0)
            dp.insert(make_pair(begin,ans));
        return ans;
    }
};


int main() {
    Solution sol;
    string beginWord="red";
    string endWord="tax";
    vector<string> list;
    list.push_back("ted");
    list.push_back("tex");
    list.push_back("red");
    list.push_back("tax");
    list.push_back("tad");
    list.push_back("den");
    list.push_back("rex");
    list.push_back("pee");
    vector<vector<string> > res = sol.findLadders(beginWord,endWord,list);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res.at(i).size();j++){
            cout<<res.at(i).at(j)<<" ";
        }
        cout<<"\n";
    }
}
