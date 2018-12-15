#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int maxi;
    vector<int> stk;
    vector<int> exp;
    vector<int> optimalExp;
    void generateOptimalExp(int ind,int op,int cl){
        int val;
        if(ind==exp.size()){
            vector<int> ans;
            vector<int> temp;
            for(int i=0;i<stk.size();i++){
                if(stk[i]==1){
                    while(*(ans.end()-1)!=0){
                        temp.push_back(*(ans.end()-1));
                        ans.pop_back();
                    }
                    ans.pop_back();
                    for(int j=temp.size()-1;j>=0;j--){
                        if(j==temp.size()-1)
                            val=temp[j];
                        else
                            val=val/temp[j];
                    }
                    ans.push_back(val);
                } else{
                    ans.push_back(stk[i]);
                }
            }
            if(ans[0]>maxi){
                maxi=ans[0];
                optimalExp=stk;
            }
        }
        val=exp[ind];

        stk.push_back(val);
        generateOptimalExp(ind+1,op,cl);
        stk.pop_back();

        stk.push_back(0);
        stk.push_back(val);
        generateOptimalExp(ind+1,op+1,cl);
        stk.pop_back();
        stk.pop_back();
        if(op>cl){
            stk.push_back(val);
            stk.push_back(1);
            generateOptimalExp(ind+1,op,cl+1);
            stk.pop_back();
            stk.pop_back();
        }
    }
public:
    string optimalDivision(vector<int>& nums) {
        exp=nums;
        maxi=0;
        generateOptimalExp(0,0,0);
        string s="";
        for(int i=0;i<optimalExp.size();i++){
            if(optimalExp[i]==1){
                s=s+'(';
            }else if(optimalExp[i]==0){
                s=s+')';
            }else{
                s=s+(char)optimalExp[i];
            }
        }
        return s;
    }
};
