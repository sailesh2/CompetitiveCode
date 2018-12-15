#include<bits/stdc++.h>

using namespace std;
struct segments{
    int val;
    int status;
};
bool fun(struct segments a, struct segments b){
    if(a.val==b.val)
        return a.status>b.status;
    else
        return a.val<b.val;
}
int main(){
    int n;
    cin>>n;
    vector<struct segments> segs;
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            segments seg1;
            seg1.val=i;
            seg1.status=0;
            segs.push_back(seg1);

            segments seg2;
            seg2.val=j;
            seg2.status=1;
            segs.push_back(seg2);
        }
    }

    sort(segs.begin(),segs.end(),fun);
    int ctr=0,maxi=0;
    for(int i=0;i<segs.size();i++){

        segments seg=segs[i];
        //cout<<seg.val<<" "<<seg.status<<"\n";
        if(seg.status==0){
            ctr++;
        }else{
            ctr=max(0,ctr-1);
        }
        maxi=max(maxi,ctr);
    }
    cout<<maxi;

    return 0;
}
