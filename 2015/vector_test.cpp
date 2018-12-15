#include<stdio.h>
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

int main()
{
    vector< pair<int,int> > v;
    vector< pair<int,int> >::iterator it;
    v.push_back(make_pair(2,3));
    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<" "<<v[i].second;
    cout<<"\n";
    it=v.end()-1;
    cout<<it->first;
}
