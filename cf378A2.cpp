#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>


using namespace std;

int main(){
    string s;
    cin>>s;
    int maxi=0,save=-1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='Y'){
            maxi=max(i-save,maxi);
            save=i;
        }

    }
    int l=s.length()-save;
    maxi=max(maxi,l);
    if(maxi==0)
        maxi=s.length()+1;
    cout<<maxi;

    return 0;
}
