#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int crr[n+1],has[n+1];
    for(int i=0;i<=n;i++){
        crr[i]=0;
        has[i]=0;
    }
    set<int> rem;
    set<int>::iterator remIt;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        crr[arr[i]]++;
    }

    for(int i=1;i<=n;i++){
        if(crr[i]==0){
            rem.insert(i);
        }
    }

    int ctr=rem.size();
    for(int i=0;i<n;i++){
        if(crr[arr[i]]>1){
            remIt=rem.begin();
            if(*remIt<arr[i]){

                crr[arr[i]]--;
                arr[i]=*remIt;
                crr[arr[i]]++;
                rem.erase(remIt);
            } else{
               if(has[arr[i]]==0){
                    has[arr[i]]=1;
               } else{
                    crr[arr[i]]--;
                    arr[i]=*remIt;
                    crr[arr[i]]++;
                    rem.erase(remIt);
               }
            }
        }
    }

    cout<<ctr<<"\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
