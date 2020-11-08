#include<bits/stdc++.h>

using namespace std;

#define gc getchar
long long int k;
map<long long int,long long int> cntMp;
map<long long int,long long int>::iterator cntMpIt;

map<long long int,long long int> posMp;
map<long long int,long long int>::iterator posMpIt;

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
    long long int m=arr.size();
    for(long long int i=0;i<m;i++){
        cntMpIt=cntMp.find(arr[i]);
        c=c+(cntMpIt->second);
        s=s+(arr[i])*(cntMpIt->second);
        pre[i]=s;
        preC[i]=c;
    }

    s=0;
    c=0;
    for(long long int i=m-2;i>=0;i--){
        cntMpIt=cntMp.find(arr[i+1]);
        c=c+(cntMpIt->second);
        s=s+(arr[i+1])*(cntMpIt->second);
        suf[i]=s;
        sufC[i]=c;
    }
}

long long int findPos(long long int v, vector<long long int> arr){
    long long int ctr=1;
    long long int save=-1;
    long long int save2=-1;

    posMpIt=posMp.find(v);
    if(posMpIt!=posMp.end())
        return posMpIt->second;
    long long int m=arr.size();
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
    long long int l=arr.size();
    for(long long int i=0;i<l;i++){
        long long int p=findPos(arr[i]+diff,arr);
        if((arr[i]*preC[i]-pre[i])>k)
            break;
        if( ( (arr[i]*preC[i]-pre[i])+ (suf[p]-(arr[i]+diff)*sufC[p]) )<=k)
            return true;
        if(p>=l-1)
            break;
    }

    for(long long int i=l-1;i>=0;i--){
        long long int p=findPos(arr[i]-diff,arr);
        if(p<0)
            break;
        if((suf[i]-(arr[i]*sufC[i]))>k)
            break;
        if( ( ((arr[i]-diff)*preC[p]-pre[p]) + (suf[i]-(arr[i]*sufC[i])) )<=k)
            return true;
    }

    return false;
}

long long int minDif(long long int l, long long int r,vector<long long int> arr){

    if(l==r)
        return l;
    long long int mid=(l+r)/2;
    if(isPossible(mid,arr)){
        return minDif(l,mid,arr);
    }else{
        return minDif(mid+1,r,arr);
    }
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
    for(long long int i=0;i<n;i++){
        x=lscan();
        cntMpIt=cntMp.find(x);
        long long int v=0;
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
    long long int f=0,l=arrSt[arrSt.size()-1]-arrSt[0];
    cout<<minDif(f,l,arrSt);
    return 0;
}
