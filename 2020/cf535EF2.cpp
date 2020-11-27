#include<bits/stdc++.h>

using namespace std;

struct Segment{
    int val;
    int status;
    int ind;
};

bool segSort(Segment segmentA, Segment segmentB){
    if(segmentA.val == segmentB.val)
        return segmentA.status<segmentB.status;
    return segmentA.val<segmentB.val;
}

int main(){
    int n,m,l,r;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<Segment> segments;
    int brr[m][2];
    //int maxSegments[m];
    int maxi,mini,minAl,maxAl;

    for(int i=0;i<m;i++){
        cin>>l>>r;
        brr[i][0]=l-1;
        brr[i][1]=r-1;
        Segment segmentL;
        segmentL.val=l-1;
        segmentL.status=0;
        segmentL.ind=i;

        Segment segmentR;
        segmentR.val=r-1;
        segmentR.status=1;
        segmentR.ind=i;

        segments.push_back(segmentL);
        segments.push_back(segmentR);
        /*maxi=-10000000;
        for(int j=l-1;j<=r-1;j++){
            maxi=max(arr[j],maxi);
        }
        maxSegments[i]=maxi;*/
    }

    sort(segments.begin(), segments.end(), segSort);

    vector<pair<pair<int,int>,pair<vector<int>,int> > > cutSegments;
    vector<int> lst,tList;

    int ctr=0,tVal,save,glMax=-10000000;
    for(int i=0;i<2*m;i++){
        if(segments[i].status==0){
            ctr++;
            if(ctr==1){
                save=segments[i].val;
                lst.clear();
                lst.push_back(segments[i].ind);

            }else{
                if(segments[i].val>save){
                    cutSegments.push_back(make_pair(make_pair(save, segments[i].val),make_pair(lst,ctr-1)));
                    save=segments[i].val;
                }
                lst.push_back(segments[i].ind);
            }
        }else{
            cutSegments.push_back(make_pair(make_pair(save,segments[i].val),make_pair(lst,ctr)));
            tVal = segments[i].val;
            save=tVal;
            while(i<2*m && segments[i].val == tVal && segments[i].status == 1){
                for(int j=0;j<lst.size();j++){
                    if(lst[j]!=segments[i].ind){
                        tList.push_back(lst[j]);
                    }
                }
                ctr--;
                i++;
            }
            lst.clear();
            lst = tList;
            tList.clear();
            i--;
        }
    }
    /*cout<<"CUTS\n";
    for(int i=0;i<cutSegments.size();i++){
        cout<<cutSegments[i].first.first<<" "<<cutSegments[i].first.second<<" "<<cutSegments[i].second.size()<<"\n";
    }*/
    cout<<"--\n";
    for(int i=0;i<cutSegments.size();i++){
        maxi=-10000000;
        mini=10000000;
        maxAl=-10000000;
        minAl=10000000;

        for(int j=0;j<cutSegments[i].second.first.size();j++){
            minAl=min(minAl,brr[cutSegments[i].second.first[j]][0]);
            maxAl=max(maxAl,brr[cutSegments[i].second.first[j]][1]);
        }
        for(int j=cutSegments[i].first.first;j<=cutSegments[i].first.second;j++){
            mini=min(mini,arr[j]);
            maxi=max(maxi,arr[j]-cutSegments[i].second.second);
        }
        for(int j=0;j<n;j++){
            if(j< minAl || j> maxAl){
                maxi=max(maxi,arr[j]);
            }
        }
        //cout<<mini<<" "<<maxi-(mini*cutSegments[i].second.size())<<"\n";
        int v = (maxi-(mini*cutSegments[i].second.first.size()));
        if(v > glMax){
            glMax=v;
            save=i;
        }

    }
    cout<<glMax<<"\n";
    cout<<cutSegments[save].second.first.size()<<"\n";
    for(int i=0;i<cutSegments[save].second.first.size();i++){
        cout<<cutSegments[save].second.first[i] + 1<<" ";
    }
    return 0;
}
