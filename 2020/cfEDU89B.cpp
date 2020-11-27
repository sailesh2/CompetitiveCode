#include<bits/stdc++.h>

using namespace std;

struct Segment{
    int pos;
    int status;
};

bool segmentComp(Segment a, Segment b){
    if(a.pos == b.pos)
        return a.status<b.status;
    return a.pos < b.pos;
}

int main(){
    int t,n,x,m,l,r;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>x>>m;
        vector<Segment> segments;
        for(int j=0;j<m;j++){
            cin>>l>>r;
            Segment segment;
            segment.pos=l;
            segment.status=0;

            segments.push_back(segment);

            Segment segment2;
            segment2.pos=r;
            segment2.status=1;

            segments.push_back(segment2);
        }

        sort(segments.begin(), segments.end(), segmentComp);

        int ans=0;
        int save=0;
        int ctr=0;
        int cnt=0;

        for(int j=0;j<segments.size();j++){

            Segment segment = segments[j];

            if(segment.status==0){
                ctr++;
            }else{
                ctr--;
            }

            //cout<<ctr<<"\n";
            if(ctr==0){
                //cout<<x<<" "<<save<<" "<<segment.pos;
                if(x>=save && x<=segment.pos){
                    ans=segment.pos-save+1;
                    break;
                }
                cnt=0;
            }else if(ctr==1 && cnt==0){
                save=segment.pos;
                cnt=1;
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}
