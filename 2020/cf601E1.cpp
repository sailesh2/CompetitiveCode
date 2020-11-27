#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int s=0,ctr=0,save=0,ctr2=0;
    vector<int> pre,disL;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==1){
            if(ctr%2==0)
                save=i;
            else
                s=s+i-save;

            ctr++;
            pre.push_back(s);
            disL.push_back(i-save);
        }
    }

    if(ctr%2==0){
        cout<<s;
    }else{
        if(ctr==1){
            cout<<"-1";
        }else{
        ctr2=0;
        save=0;
        int post[ctr],disR[ctr];
        for(int i=n-1;i>=0;i--){
             if(arr[i]==1){
                if(ctr2%2==0)
                    save=i;
                else
                    s=s+save-i;

                ctr2++;
                post[ctr-ctr2]=(s);

                disR[ctr-ctr2]=save-i;
            }
        }
        int mini=s;
        /*for(int i=1;i<ctr;i=i+2){
            if(i+2<ctr)
            mini=min(mini,pre[i] + post[i+2] + min(disL[i],disR[i]));
        }*/
        for(int i=1;i<ctr;i=i+2){
            if(i-2>=0 && i+2<ctr)
            mini=min(mini,pre[i-2] + post[i+2] + disL[i-1]+disR[i+1]);
        }
        cout<<mini;
        }
    }
    return 0;
}
