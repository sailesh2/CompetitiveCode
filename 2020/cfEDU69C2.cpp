#include<bits/stdc++.h>

using namespace std;
#define gc getchar

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
    int n,k;
    long long int sm=0;
    n=lscan();
    k=lscan();
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=lscan();
    }

    vector<pair<int,int> > diff;
    for(int i=0;i<n-1;i++){
        diff.push_back(make_pair(arr[i+1]-arr[i],i));
    }

    sort(diff.begin(),diff.end());
    int last=n-1;
    for(int i=diff.size()-1;i>=0;i--){
        if(k==1){
            sm=sm+(long long int)(arr[last]-arr[0]);
            k--;
            break;
        }
        int p=diff[i].second;

        sm=sm+(long long int)(arr[last]-arr[(p+1)]);
        last=p;
        k--;
    }

    if(k>0)
        cout<<"0";
    else
        cout<<sm;

    return 0;
}
