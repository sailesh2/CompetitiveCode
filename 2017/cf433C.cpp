#include<bits/stdc++.h>
#define gc getchar
using namespace std;
inline int lscan()
{
int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}
int main(){
    int n,k,temp,ind,tempInd;
    cin>>n>>k;
    long long int sm=0,tempV,val;
    int ini[n],arr[n],brr[n];
    set<pair<int,int> > s;
    set<pair<int,int> >::iterator sIt;
    for(int i=0;i<n;i++){
        arr[i]=lscan();
        s.insert(make_pair(arr[i],i));
        brr[i]=i;
        ini[i]=arr[i];
    }
    int ctr=0,v;
    int has[300005]={0};
    while(s.size()>0){
        sIt=s.end();
        sIt--;
        val=sIt->first;
        ind=sIt->second;
        //cout<<val<<" "<<ind<<"\n";
        v=brr[ind]-k;
        tempInd=max(v,ctr);
        //cout<<val<<" "<<ind<<" "<<tempInd<<"\n";

        tempV=arr[tempInd];
        if(val>=tempV){
            if(ind!=tempInd){
                arr[ind]=tempV;
                arr[tempInd]=val;

                temp=brr[ind];
                brr[ind]=brr[tempInd];
                brr[tempInd]=temp;
            }
            has[tempInd]=1;
            while(ctr<=n && has[ctr]==1){
                ctr++;
            }
        }
        //cout<<tempInd<<" "<<brr[tempInd]<<"\n";
        //cout<<ind<<" "<<brr[ind]<<"\n";
        s.erase(sIt);
        if(val>=tempV){
            if(ind!=tempInd){
                sIt=s.find(make_pair(tempV,tempInd));
                if(sIt!=s.end()){
                    s.erase(sIt);
                    s.insert(make_pair(tempV,ind));
                }
            }
        }
    }
    int ans[n];
    for(int i=0;i<n;i++){
        ans[brr[i]]=i;
        sm=sm+((long long int)(i+k-brr[i]))*ini[brr[i]];
    }

    cout<<sm<<"\n";
    for(int i=0;i<n;i++){
        cout<<ans[i]+k+1<<" ";
    }
    return 0;
}
