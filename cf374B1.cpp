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
    int n,k;
    cin>>n>>k;
    string s;
    pair<int,string> pr[n];
    for(int i=0;i<n;i++){
        cin>>s;
        pr[i]=make_pair(s.length(),s);
    }

    sort(pr,pr+n);
    string pass;
    cin>>pass;

    int bctr=0,bcnt=0,wcnt=0,wctr=0;
    for(int i=0;i<n;i++){
        if(pr[i].first==pass.length()){
            bctr++;
            break;
        } else{
            bctr++;
            bcnt++;
            if(bcnt==k){
                bcnt=0;
                bctr=bctr+5;
            }
        }
    }

int cnt=0;
    for(int i=0;i<n;i++){
        if(pr[i].first>pass.length()){
            break;
        } else{
            wctr++;
            wcnt++;
            if(wcnt==k){
                wcnt=0;
                if(pr[i].first==pass.length()){
                    if(i+1==n || pr[i+1].first>pass.length())
                        cnt=1;
                }
                wctr=wctr+5;
            }
        }
    }

    if(cnt==1){
        wctr=wctr-5;
    }
    cout<<bctr<<" "<<wctr;
    return 0;
}
