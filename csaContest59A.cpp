#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int has[300]={0};
    for(int i=0;i<n;i++){
        has[s[i]]++;
    }
    int save=-1;
    for(int i=0;i<n;i++){
        if(has[s[i]]==1){
            save=i;
            break;
        }
    }
    if(save==-1)
        cout<<save;
    else
        cout<<s[save];
    return 0;
}
