#include<bits/stdc++.h>
#include<algorithm>

using namespace std;


bool fun(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}
int main(){
    vector<pair<int,int> > v;
    sort(v.begin(),v.end(),fun);
    return 0;
}


class Solution {
public:

    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
        sort(people.begin(),people.end(),fun);
        vector<pair<int,int> > ans;
        int ctr;
        for(int i=0;i<people.size();i++){
            ctr=0;
            int j;
            for(j=0;j<ans.size();j++){
                if(ans[j].first<=people[i].first){
                    ctr++;
                }
                if(ctr==people[i].second)
                    break;
            }

            int save=j;
            j++;
            for(;j<ans.size();j++){
                if(ans[j].first<people[i].first){
                    save=j;
                }
            }
            ans.insert(ans.begin()+save+1,people[i]);
        }
        return ans;
    }
};
