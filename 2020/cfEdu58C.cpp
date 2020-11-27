#include<bits/stdc++.h>

using namespace std;

struct segment{
    int data;
    int status;
    int index;
};

bool comp(segment a, segment b){
    if(a.data==b.data)
        return a.status<b.status;
    else
        return a.data<b.data;
}

int main(){
    int t,n,l,r,ctr,cnt,emptySeat;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int ans[n];
        vector<int> lower;
        vector<int> upper;
        vector<segment> segments;
        for(int j=0;j<n;j++){
            cin>>l>>r;
            ans[j]=1;
            segment segmentL;
            segmentL.data=l;
            segmentL.status=0;
            segmentL.index=j;
            segments.push_back(segmentL);

            segment segmentR;
            segmentR.data=r;
            segmentR.status=1;
            segmentR.index=j;
            segments.push_back(segmentR);
        }
        sort(segments.begin(),segments.end(),comp);
        ctr=0;
        emptySeat=0;
        for(int j=0;j<segments.size();j++){
            if(segments[j].status==0)
                ctr++;
            else
                ctr--;

            if(ctr>0){
                if(segments[j].status==0){
                    if(ctr==1){
                        if(upper.size()==0)
                            emptySeat=0;
                        else
                            emptySeat=1;
                    }

                    if(emptySeat==0){
                        upper.push_back(segments[j].index);
                   }else{
                        lower.push_back(segments[j].index);
                    }
                }
            }

        }

        if(lower.size()==0 || upper.size()==0){
            cout<<"-1";
        }else{

            for(int j=0;j<upper.size();j++){
                ans[upper[j]]=2;
            }

            for(int j=0;j<n;j++){
                cout<<ans[j]<<" ";
            }
        }

        cout<<"\n";
    }
    return 0;
}
