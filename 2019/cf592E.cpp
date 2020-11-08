#include<bits/stdc++.h>

using namespace std;

#define gc getchar
long long int k;
map<long long int,int> cntMp;
map<long long int,int>::iterator cntMpIt;

map<long long int,int> posMp;
map<long long int,int>::iterator posMpIt;

long long int pre[100005]={0};
long long int preC[100005]={0};
long long int suf[100005]={0};
long long int sufC[100005]={0};

inline long long int lscan()
{
long long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

void setup(vector<long long int> arr){
    long long int s=0,c=0;
    int m=arr.size();
    for(int i=0;i<m;i++){
        cntMpIt=cntMp.find(arr[i]);
        c=c+(cntMpIt->second);
        s=s+(arr[i])*(cntMpIt->second);
        pre[i]=s;
        preC[i]=c;
    }

    s=0;
    c=0;
    for(int i=m-2;i>=0;i--){
        cntMpIt=cntMp.find(arr[i+1]);
        c=c+(cntMpIt->second);
        s=s+(arr[i+1])*(cntMpIt->second);
        suf[i]=s;
        sufC[i]=c;
    }
}

int findPos(long long int v, vector<long long int> arr){
    int ctr=1;
    int save=-1;
    int save2=-1;

    posMpIt=posMp.find(v);
    if(posMpIt!=posMp.end())
        return posMpIt->second;
    int m=arr.size();
    while(1){
        while(save+ctr<m && arr[save+ctr]<=v){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }

    posMp.insert(make_pair(v,save));
    return save;
}

bool isPossible(long long int diff, vector<long long int> arr){
    int l=arr.size();
    for(int i=0;i<l;i++){
        int p=findPos(arr[i]+diff,arr);
        if((arr[i]*preC[i]-pre[i])>k)
            break;
        if( ( (arr[i]*preC[i]-pre[i])+ (suf[p]-(arr[i]+diff)*sufC[p]) )<=k)
            return true;
        if(p>=l-1)
            break;
    }

    for(int i=l-1;i>=0;i--){
        int p=findPos(arr[i]-diff,arr);
        if(p<0)
            break;
        if((suf[i]-(arr[i]*sufC[i]))>k)
            break;
        if( ( ((arr[i]-diff)*preC[p]-pre[p]) + (suf[i]-(arr[i]*sufC[i])) )<=k)
            return true;

    }

    return false;
}

long long int minDif(vector<long long int> arr){
    int m=arr.size()-1;
    long long int dif = arr[m]-arr[0];
    long long int ctr=1;
    long long int save=-1;
    long long int save2=-1;

    while(1){
        while(save+ctr<=dif && !isPossible(save+ctr,arr)){
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

void display(vector<long long int> arrSt){
    for(long long int i=0;i<arrSt.size();i++){
        cout<<pre[i]<<" ";
    }
    cout<<"\n";
    for(long long int i=0;i<arrSt.size();i++){
        cout<<suf[i]<<" ";
    }
}
int main(){
    long long int n;
    n=lscan();
    k=lscan();
    long long int x;
    vector<long long int> arrSt;
    for(int i=0;i<n;i++){
        x=lscan();
        cntMpIt=cntMp.find(x);
        int v=0;
        if(cntMpIt!=cntMp.end()){
            v=cntMpIt->second;
            cntMp.erase(cntMpIt);
        }else{
            arrSt.push_back(x);
        }
        v++;
        cntMp.insert(make_pair(x,v));
    }
    sort(arrSt.begin(),arrSt.end());
    setup(arrSt);
    //display(arrSt);
    cout<<minDif(arrSt);
    return 0;
}
