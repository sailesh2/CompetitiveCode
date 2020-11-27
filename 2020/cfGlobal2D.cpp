#include<bits/stdc++.h>

using namespace std;
long long int n;
vector<pair<long long int,long long int> > ans;
vector<long long int> remSum;

long long int maxFrets(int pos, pair<long long int,long long int>* diff, long long int d){
    long long int left=0;
    long long int right=0;
    //cout<<"p"<<pos<<"s"<<ans[pos].first<<"c"<<ans[pos].second<<"\n";
    if(pos>=0){
        left=ans[pos].first+d*(ans[pos].second) - remSum[pos];
        right=n-2-pos;
    }else{
        right=n;
    }
    return left+(right)*(d+1);
}

long long int bin(pair<long long int,long long int>* diff, long long int l, long long int r){
    long long int ctr=1;
    long long int save=-1;
    long long int save2=-1;

    while(1){
        while(save+ctr<n-1 && diff[save+ctr].first<=(r-l)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return maxFrets(save,diff,r-l);
}

int main(){
    long long int n2;
    cin>>n2;
    long long int s;
    long long int l,r;
    vector<long long int> frets;
    set<long long int> has;
    for(long long int i=0;i<n2;i++){
        cin>>s;
        if(has.count(s)==0){
            frets.push_back(s);
            has.insert(s);
        }
    }
    if(n2==1){
        long long int q;
        cin>>q;
        for(long long int i=0;i<q;i++){
            cin>>l>>r;
            cout<<r-l+1<<" ";
        }

    }else{
        sort(frets.begin(),frets.end());
        n=frets.size();
        pair<long long int,long long int> diff[n-1];
        for(long long int i=1;i<n;i++){
            diff[i-1]=(make_pair(frets[i]-frets[i-1],i));
        }
        sort(diff,diff+n-1);
        long long int sm=0,ctr=0,rs=0;
        set<pair<long long int,long long int> > cumlLeft;
        set<pair<long long int,long long int> >::iterator cumlLeftIt;
        long long int remSumHas[100005]={0};
        for(long long int i=0;i<n-1;i++){
            cumlLeft.insert(make_pair(frets[diff[i].second],i));
            cumlLeftIt = cumlLeft.find(make_pair(frets[diff[i].second],i));
            long long int leftBorder=frets[diff[i].second-1];
            long long int rightBorder=frets[diff[i].second]+diff[i].first;
            if(cumlLeftIt != cumlLeft.begin()){
                cumlLeftIt--;
                if(frets[diff[i].second-1] - ((cumlLeftIt->first) + (diff[cumlLeftIt->second].first)) <= diff[i].first){
                    leftBorder=(cumlLeftIt->first)+diff[cumlLeftIt->second].first+1;
                    ctr--;
                    rs=rs-remSumHas[diff[cumlLeftIt->second].second];
                }

                cumlLeftIt++;
            }
            cumlLeftIt++;
            if(cumlLeftIt!=cumlLeft.end()){
                if((frets[diff[cumlLeftIt->second].second-1] - frets[diff[i].second])  <= diff[i].first){
                    rightBorder=(frets[diff[cumlLeftIt->second].second-1])-1;
                }else{
                    rightBorder = frets[diff[i].second] + diff[i].first;
                    ctr++;
                    rs=rs+diff[i].first;
                    remSumHas[diff[i].second]=rs;
                }

            }else{
                ctr++;
                rs=rs+diff[i].first;
                remSumHas[diff[i].second]=rs;
            }
            //cout<<ctr<<"\n";
            remSum.push_back(rs);
            sm=sm+rightBorder-leftBorder+1;
            ans.push_back(make_pair(sm,ctr));
        }

        long long int q;
        cin>>q;
        for(long long int i=0;i<q;i++){
            cin>>l>>r;
            cout<<bin(diff,l,r)<<" ";
        }
    }
    return 0;
}
