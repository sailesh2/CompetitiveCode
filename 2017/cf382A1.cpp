#include<stdio.h>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    int cnt=0,gh,in;
    for(int i=0;i<n;i++){
        if(s[i]=='G'){
            gh=i;
        }
        if(s[i]=='T'){
            in=i;
        }
    }

    for(int i=gh;i<n;){
        if(s[i]=='T'){
            cnt=1;
            break;
        }

        if(s[i]=='#'){
            break;
        }
        i=i+k;
    }

    for(int i=gh;i>=0;){
        if(s[i]=='T'){
            cnt=1;
            break;
        }


        if(s[i]=='#'){
            break;
        }
        i=i-k;
    }

    if(cnt==1){
        cout<<"YES";
    } else{
        cout<<"NO";
    }
    return 0;
}
