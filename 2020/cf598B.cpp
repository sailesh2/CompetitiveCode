#include<bits/stdc++.h>

using namespace std;

int main(){
    int q,n;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>n;
        int arr[n];
        int ans[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
            ans[j]=arr[j];
        }
        int index=0;
        while(index<n){
            int mini=ans[index];
            int save=-1;
            for(int k=index;k<n;k++){
                if(ans[k]<mini){
                    mini=ans[k];
                    save=k;
                }
            }
            if(save==-1){
                index++;
                continue;
            }
            int temp=ans[save];
            for(int k=save-1;k>=index;k--){
                ans[k+1]=ans[k];
            }
            ans[index]=temp;

            index=save;
        }
        for(int j=0;j<n;j++)
            cout<<ans[j]<<" ";
        cout<<"\n";
    }
    return 0;
}
