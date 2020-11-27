#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        int arr[n];

        map<int,int> has;
        map<int,int>::iterator hasIt;
        int cnt[n+1];
        cnt[0]=0;
        for(int j=0;j<n;j++){
            cin>>arr[j];
            if(arr[j]>k)
                arr[j]=1;
            else if(arr[j]<k)
                arr[j]=-1;
            else
                arr[j]=0;
            cnt[j+1]=cnt[j];
            if(arr[j]==0)
                cnt[j+1]++;
        }

        int s=0,ctr=0;
        for(int j=0;j<n;j++){
            s=s+arr[j];
            hasIt = has.find(s);
            if(hasIt!=has.end() && ((j+1-(hasIt->second))>1) && ((cnt[j+1]-cnt[hasIt->second])>0)){
                ctr=1;
                break;
            }

            hasIt = has.find(s-1);
            if(hasIt!=has.end() && ((j+1-(hasIt->second))>1) && ((cnt[j+1]-cnt[hasIt->second])>0)){
                ctr=1;
                break;
            }

            hasIt = has.find(s+1);
            if(hasIt!=has.end() && ((j+1-(hasIt->second))>1) && ((cnt[j+1]-cnt[hasIt->second])>0)){
                ctr=1;
                break;
            }

            hasIt=has.find(s);
            if(hasIt==has.end())
            has.insert(make_pair(s,j+1));
        }

        if(ctr==1 || (n==1 && arr[0]==0))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
