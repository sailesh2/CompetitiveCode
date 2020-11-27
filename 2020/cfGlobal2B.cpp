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
    int n,h;
    n=lscan();
    h=lscan();
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=lscan();
    }
    int maxi=0;
    vector<int> bottles;
    for(int i=0;i<n;i++){
        bottles.push_back(arr[i]);
        int cnt=0,possible=0;
        int left=h;
        sort(bottles.begin(),bottles.end());
        for(int j=bottles.size()-1;j>=0;j--){
            if(cnt==0){
                if(bottles[j]<=left){
                    left=left-bottles[j];
                }else{
                    possible=1;
                    break;
                }
            }
            cnt=1-cnt;
        }
        if(possible==1){
            break;
        }
        maxi=i;
    }
    cout<<maxi+1;
    return 0;
}
