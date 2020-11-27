#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    string s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        int cnt=0;
        int has[300];
        for(char j='a';j<='z';j++)
            has[(int)j]=100;
        set<int> taken;
        int minI;
        for(int j=0;j<s.length();j++){

            if(j>0){
                if(has[(int)s[j]]==100){

                    if(taken.count(has[(int)s[j-1]]+1)==0){

                        has[(int)s[j]]=has[(int)s[j-1]]+1;
                        taken.insert(has[(int)s[j-1]]+1);

                    }else if(taken.count(has[(int)s[j-1]]-1)==0){
                        has[(int)s[j]]=has[(int)s[j-1]]-1;
                        taken.insert(has[(int)s[j-1]]-1);
                        minI=min(minI,has[(int)s[j-1]]-1);
                    }else{
                        cnt=1;
                        break;
                    }
                }else{
                    if(abs(has[(int)s[j]]-has[(int)s[j-1]])!=1){
                        cnt=1;
                        break;
                    }
                }

            }else{
                has[(int)s[j]]=0;
                taken.insert(0);
                minI=0;
            }
        }
        if(cnt==0){
            char ans[26];
            for(char j='a';j<='z';j++){
                ans[j-'a']='0';
            }
            for(char j='a';j<='z';j++){
                if(has[(int)j]!=100){
                    ans[abs(minI)+has[(int)j]]=j;
                }
            }
            for(char j='a';j<='z';j++){
                if(has[(int)j]==100){
                    for(int k=0;k<26;k++){
                        if(ans[k]=='0'){
                            ans[k]=j;
                            break;
                        }
                    }
                }
            }
            cout<<"YES\n";
            for(int j=0;j<26;j++)
                cout<<ans[j];
            cout<<"\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
