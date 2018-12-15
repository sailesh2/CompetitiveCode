#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v2;


int binSearLow(int cost){
    int ctr=1;
    int save=-1;
    int save2=-1;

    int k=v2.size();
    while(1){
        while(save+ctr<k && v2[save+ctr].first<cost){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save+1;
}

int binSearHigh(int cost){
    int ctr=1;
    int save=-1;
    int save2=-1;

    int k=v2.size();
    while(1){
        while(save+ctr<k && v2[save+ctr].second<=cost){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save;
}


struct paint{
    int ind;
    int painter;
    int status;
};

bool fun(struct paint a, struct paint b){
    if(a.ind==b.ind){
        return a.status<b.status;
    }else{
        return a.ind<b.ind;
    }
}
int main(){
    int n,m,l,r;
    cin>>n>>m;
    int arr[m][2];
    vector<struct paint> v;
    for(int i=0;i<m;i++){
        cin>>l>>r;
        arr[i][0]=l;
        arr[i][1]=r;
        struct paint p1,p2;
        p1.ind=l;
        p1.painter=i;
        p1.status=0;

        p2.ind=r;
        p2.painter=i;
        p2.status=1;

        v.push_back(p1);
        v.push_back(p2);
    }
    sort(v.begin(),v.end(),fun);

    int paintLeft[100005]={0};
    int ctr=0;

    int com=0;
    int save,csave=1,cnt=0;
    for(int i=0;i<v.size();i++){
        if(v[i].status==0){
            ctr++;
        }else{
            ctr--;
        }
        if(cnt==0){
            if(ctr==1){
                if(csave!=-1)
                    com=com+v[i].ind-csave;
                cnt=1;
                if(v[i].status==0)
                    save=v[i].ind;
                else
                    save=v[i].ind+1;
                csave=-1;
            }
        }else{
            if(ctr==0){
                csave=v[i].ind+1;
                paintLeft[v[i].painter]=paintLeft[v[i].painter]+(v[i].ind-save+1);
            }else if(ctr==2){
                if(save<=(v[i].ind-1))
                    v2.push_back(make_pair(save,v[i].ind-1));
            }
            cnt=0;
        }
    }

    /*if(cnt==1 && v[v.size()-1].ind+1<=n){
        v2.push_back(make_pair(v[v.size()-1].ind+1,n));
    }*/
    if(cnt==0 && csave!=-1){
        com=com+n-csave+1;
    }

    /*for(int i=0;i<v2.size();i++){
        cout<<v2[i].first<<" "<<v2[i].second<<"\n";
    }*/

    int fs,fe;
    for(int i=0;i<m;i++){
        fs=binSearLow(arr[i][0]);
        fe=binSearHigh(arr[i][1]);
        //cout<<i<<" "<<fs<<" "<<fe<<"\n";
        if(fs<=fe && fs>=0 && fs<m && fe>=0 && fe<m){

            for(int j=fs;j<=fe;j++){
                if(v2[j].first>=arr[i][0] && v2[j].second<=arr[i][1]){
                    paintLeft[i]=paintLeft[i]+v2[j].second-v2[j].first+1;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<paintLeft[i]+com<<"\n";
    }
    return 0;
}
