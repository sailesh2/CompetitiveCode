#include<bits/stdc++.h>

using namespace std;

map<int,pair<int,int> > linkedList;
map<int,pair<int,int> >::iterator linkedListIt;
map<int,pair<int,int> >::iterator linkedListIt2;

void updatePairsLeft(int curr, int next){
    linkedListIt = linkedList.find(next);
    pair<int,int> p = linkedListIt->second;

    if(p.first==-1){
        linkedList.erase(linkedListIt);
        linkedList.insert(make_pair(next, make_pair(curr,-1)));
        return;
    }else{
        updatePairsLeft(next, p.first);
    }

    linkedList.erase(linkedListIt);
    linkedList.insert(make_pair(next, make_pair( curr, p.first)));

}

void updatePairsRight(int curr, int prev){
    linkedListIt = linkedList.find(prev);
    pair<int,int> p = linkedListIt->second;

    if(p.second==-1){
        linkedList.erase(linkedListIt);
        linkedList.insert(make_pair(prev, make_pair(-1, curr)));
        return;
    }else{
        updatePairsRight(prev, p.second);
    }

    linkedList.erase(linkedListIt);
    linkedList.insert(make_pair(prev, make_pair(p.second, curr)));

}

void updateLinkedList(int present, int notPresent){
    linkedListIt = linkedList.find(present);
    pair<int,int> p = linkedListIt->second;
    if(p.first==-1){
        p.first=notPresent;
        updatePairsRight(present, notPresent);
        linkedList.insert(make_pair(present, p));
    }else{
        p.second=notPresent;
        updatePairsLeft(present, notPresent);
        linkedList.insert(make_pair(present, p));
    }
}

int main(){
    int n;
    cin>>n;
    int x,y;

    for(int i=1;i<=n;i++){
        linkedList.insert(make_pair(i,make_pair(-1,-1)));
    }

    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        updateLinkedList(x,y);
    }

    int start=-1;
    for(int i=1;i<=n;i++){
        linkedListIt=linkedList.find(i);
        if((linkedListIt->second).first==-1){
            start=i;
            break;
        }
    }

    while(start!=-1){
        cout<<start<<" ";
        linkedListIt = linkedList.find(start);
        start = (linkedListIt->second).second;
    }

    return 0;
}
