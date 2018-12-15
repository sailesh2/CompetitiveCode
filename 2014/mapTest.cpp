#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<int,int> mp;
    map<int,int>::iterator it;
    mp.insert(pair<int,int>(2,3));
    //mp.at(0);
    //cout<<it->first<<"       "<<it->second;
    it=mp.find(2);
    cout<<it->second;
    return 0;
}
