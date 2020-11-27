#include<bits/stdc++.h>

using namespace std;
long long int nr,ng,nb;

vector<long long int> arr[3];

long long int getV(long long int* ind, long long int* maxInd){
    long long int x = arr[0][min(ind[0],maxInd[0]-1)];
    long long int y = arr[1][min(ind[1],maxInd[1]-1)];
    long long int z = arr[2][min(ind[2],maxInd[2]-1)];

    return (x-y)*(x-y) + (y-z)*(y-z) + (x-z)*(x-z);
}

long long int getSmallest3(long long int* ind){
    if(arr[0][ind[0]+1]<=arr[1][ind[1]+1] && arr[0][ind[0]+1]<=arr[2][ind[2]+1]){
        return 0LL;
    }

    if(arr[1][ind[1]+1]<=arr[0][ind[0]+1] && arr[1][ind[1]+1]<=arr[2][ind[2]+1]){
        return 1LL;
    }

    if(arr[2][ind[2]+1]<=arr[1][ind[1]+1] && arr[2][ind[2]+1]<=arr[0][ind[0]+1]){
        return 2LL;
    }

    return -1;
}

long long int getSmallest2(long long int a, long long int b, long long int* ind){
    if(arr[a][ind[a]+1]<=arr[b][ind[b]+1]){
        return a;
    }else{
        return b;
    }
}

long long int getNext(long long int* ind, long long int* maxInd){

    if(ind[0]+1<maxInd[0] && ind[1]+1<maxInd[1] && ind[2]+1<maxInd[2]){
        return getSmallest3(ind);
    }else{
        if(ind[0]+1<maxInd[0] && ind[1]+1<maxInd[1]){
            return getSmallest2(0,1,ind);
        }else if(ind[1]+1<maxInd[1] && ind[2]+1<maxInd[2]){
            return getSmallest2(1,2,ind);
        }else if(ind[0]+1<maxInd[0] && ind[2]+1<maxInd[2]){
            return getSmallest2(0,2,ind);
        }else{
            if(ind[0]+1<maxInd[0]){
                return 0LL;
            }else if(ind[1]+1<maxInd[1]){
                return 1LL;
            }else if(ind[2]+1<maxInd[2]){
                return 2LL;
            }else{
                return -1;
            }
        }
    }
}

long long int calMin(vector<long long int> r,vector<long long int> g, vector<long long int>  b){
    sort(r.begin(),r.end());
    sort(g.begin(),g.end());
    sort(b.begin(),b.end());

    arr[0]=r;
    arr[1]=g;
    arr[2]=b;

    long long int ind[3];
    ind[0]=0LL;
    ind[1]=0LL;
    ind[2]=0LL;

    long long int maxInd[3];
    maxInd[0]=nr;
    maxInd[1]=ng;
    maxInd[2]=nb;

    long long int mini=-1;
    while(1){
        long long int v = getV(ind,maxInd);
        if(mini==-1)
            mini=v;
        else
            mini=min(mini,v);
        long long int lowInd = getNext(ind,maxInd);
        if(lowInd==-1)
            break;
        ind[lowInd]++;
    }
    return mini;
}

int main(){
    long long int t;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>nr>>ng>>nb;
        vector<long long int> r;
        vector<long long int> g;
        vector<long long int> b;
        long long int x;
        for(long long int j=0;j<nr;j++){
            cin>>x;
            r.push_back(x);
        }

        for(long long int j=0;j<ng;j++){
            cin>>x;
            g.push_back(x);
        }

        for(long long int j=0;j<nb;j++){
            cin>>x;
            b.push_back(x);
        }
        cout<<calMin(r,g,b)<<"\n";
    }
    return 0;
}
