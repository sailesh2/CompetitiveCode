#include<bits/stdc++.h>

using namespace std;

struct Segment{
    int type;
    int left;
    int right;
};

bool segmentComp(Segment a, Segment b){
    if(a.left == b.left){
        return a.right<b.right;
    }
    return a.left<b.left;
}

int main(){
    int n,m;
    cin>>n>>m;
    int t,l,r;
    vector<Segment> segments;
    for(int i=0;i<m;i++){
        cin>>t>>l>>r;
        Segment seg;
        seg.type=t;
        seg.left=l-1;
        seg.right=r-1;

        segments.push_back(seg);
    }

    sort(segments.begin(),segments.end(),segmentComp);

    int arr[n];
    int has[100005]={0};
    int MAX=1000000000;
    int cnt2=0;
    for(int i=0;i<m;i++){
        t=segments[i].type;
        l=segments[i].left;
        r=segments[i].right;
        int cnt=0;
        if(t==0){
            for(int j=l;j<=r;j++){
                if(has[j]==0){
                    if(j==0){
                        if(j+1<n){
                            has[j]=1;
                            has[j+1]=1;
                            arr[j+1]=MAX-1;
                            arr[j]=MAX;
                            cnt=1;
                            break;
                        }
                    }else{
                        arr[j]=arr[j-1]-1;
                        has[j]=1;
                        cnt=1;
                        break;
                    }
                }
            }
            if(cnt==0)
            {
                cnt2=1;
                break;
            }

        }else{
            for(int j=l;j<=r;j++){

                if(has[j]==1){
                    if(j>l && has[j]<has[j-1]){
                        cnt=1;
                        break;
                    }
                }else{
                    has[j]=1;
                    if(j==l)
                    arr[j]=MAX;
                    else
                    arr[j]=arr[j-1];
                }
            }

            if(cnt==1)
            {
                cnt2=1;
                break;
            }
        }
    }
    if(cnt2==1){
        cout<<"NO";
    }else{
        for(int i=0;i<n;i++){
            if(has[i]==0){
                arr[i]=1;
            }
        }

        for(int i=0;i<n;i++){
            if(arr[i]<1 || arr[i]>MAX){
                cnt2=1;
                break;
            }
        }
        if(cnt2==1){
            cout<<"NO";
        }else{

        cout<<"YES\n";
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}
