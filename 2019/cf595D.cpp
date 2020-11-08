#include<bits/stdc++.h>

using namespace std;

struct Segment{
    int pos;
    int ind;
    int status;
    int next;
};

bool segmentComp(Segment a, Segment b){
    if(a.pos==b.pos){
        if(a.next==b.next)
            return a.status<b.status;
        else
            return a.next>b.next;
    }
    return a.pos<b.pos;
}

int main(){
    int n,k,l,r;
    cin>>n>>k;
    int arr[n][2];
    vector<Segment> segments;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        arr[i][0]=l;
        arr[i][1]=r;
        Segment segment;
        segment.ind=i;
        segment.pos=l;
        segment.status=0;
        segment.next=r;

        segments.push_back(segment);

        Segment segment2;
        segment2.ind=i;
        segment2.pos=r;
        segment2.status=1;
        segment2.next=r;

        segments.push_back(segment2);
    }

    sort(segments.begin(),segments.end(),segmentComp);

    set<pair<int,int> > segmentTaken;
    set<pair<int,int> >::iterator segmentTakenIt;
    set<int> has;
    int ctr=0;
    vector<int> ans;
    for(int i=0;i<segments.size();i++){
        Segment segment = segments[i];
        if(segment.status==0){
                ctr++;
                segmentTaken.insert(make_pair(arr[segment.ind][1],segment.ind));

        }else{
            if(has.count(segment.ind)==0){
                ctr--;
                segmentTaken.erase(segmentTaken.find(make_pair(segment.pos,segment.ind)));
            }
        }

        if(ctr>k){
            segmentTakenIt = segmentTaken.end();
            segmentTakenIt--;
            pair<int,int> p = *segmentTakenIt;
            has.insert(p.second);
            ans.push_back(p.second);
            segmentTaken.erase(segmentTakenIt);
            ctr--;
        }
    }

    sort(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]+1<<" ";
    }
    return 0;
}
