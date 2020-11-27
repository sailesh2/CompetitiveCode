#include<bits/stdc++.h>
#define gc getchar

using namespace std;

map<long long int,vector<long long int> > linkedList;
map<long long int,vector<long long int> >::iterator linkedListIt;

inline long long int lscan()
{
long long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}
set<long long int> has;
void display(long long int start){
    vector<long long int> next;
    linkedListIt = linkedList.find(start);
    vector<long long int> v  = linkedListIt->second;
    for(int i=0;i<v.size();i++){
        if(has.count(v[i])==0){
            has.insert(v[i]);
            cout<<v[i]<<" ";
            next.push_back(v[i]);
        }
    }

    for(int i=0;i<next.size();i++){
        display(next[i]);
    }
}

void insertLinkedList(long long int x, long long int y){
        vector<long long int> p;
        linkedListIt = linkedList.find(x);
        if(linkedListIt != linkedList.end()){
            p = linkedListIt->second;
            linkedList.erase(linkedListIt);
        }
        p.push_back(y);
        linkedList.insert(make_pair(x,p));
}

int main(){
    long long int n;
    n=lscan();
    long long int x,y;

    for(long long int i=0;i<n-1;i++){
        x=lscan();
        y=lscan();
        insertLinkedList(x,y);
        insertLinkedList(y,x);
    }

    cout<<"1 ";
    has.insert(1);
    display(1);
    return 0;
}
