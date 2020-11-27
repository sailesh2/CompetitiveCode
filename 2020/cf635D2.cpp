#include<bits/stdc++.h>

using namespace std;
int nr,ng,nb;

vector<int> arr[3];

int getV(int x, int y, int z){

    return (x-y)*(x-y) + (y-z)*(y-z) + (x-z)*(x-z);
}


int getlower(int cost, vector<int> v){
    int ctr=1;
    int save=-1;
    int save2=-1;
    int k=v.size();
    while(1){
        while(save+ctr<k && v[save+ctr]<=cost){
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


int getUpper(int cost, vector<int> v){
    int ctr=1;
    int save=-1;
    int save2=-1;
    int k=v.size();
    while(1){
        while(save+ctr<k && v[save+ctr]<=cost){
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

bool isInc(int prev, int next, int v1, int v2){
    return getV(prev,v1,v2)<=getV(next,v1,v2);
}

int getMin(int f, int s, vector<int> v){
    int v1=min(f,s);
    int v2=max(f,s);

    int ctr=1;
    int save=-1;
    int save2=-1;
    int k=v.size();
    int lf=getUpper(v1,v);
    int rt=getlower(v2,v);
    while(1){
        while(lf+save+ctr<=rt && isInc(v[lf+save+ctr],v[lf+save+ctr+1],v1,v2)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return getV(v[save],v1,v2);
}

int calMin(vector<int> r,vector<int> g, vector<int>  b){
    sort(r.begin(),r.end());
    sort(g.begin(),g.end());
    sort(b.begin(),b.end());

    arr[0]=r;
    arr[1]=g;
    arr[2]=b;

    int mini=1000000009;
    for(int i=0;i<nr;i++){
        int f=r[i];
        int s= getlower(f,g);
        if(s>=0 && s<g.size())
            mini=min(mini,getMin(f,g[s],b));

        s=getUpper(f,g);
        if(s>=0 && s<g.size())
            mini=min(mini,getMin(f,g[s],b));
    }

    return mini;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>nr>>ng>>nb;
        vector<int> r;
        vector<int> g;
        vector<int> b;
        int x;
        for(int j=0;j<nr;j++){
            cin>>x;
            r.push_back(x);
        }

        for(int j=0;j<ng;j++){
            cin>>x;
            g.push_back(x);
        }

        for(int j=0;j<nb;j++){
            cin>>x;
            b.push_back(x);
        }
        cout<<calMin(r,g,b)<<"\n";
    }
    return 0;
}
