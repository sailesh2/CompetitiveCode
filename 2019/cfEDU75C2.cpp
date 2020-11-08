#include<bits/stdc++.h>

using namespace std;

int MAX=1000000000;

bool isOdd(char a){
    int xa=(int)a-48;
    return xa%2!=0;
}

string generateSmallest(string s){
    int l=s.length();
    l++;
    int posOdd[l];
    int posEven[l];
    int save=MAX,maxiE=0,maxiO=0;
    for(int i=s.length()-1;i>=0;i--){
        if(isOdd(s[i])){
            save=i;
        }
        posOdd[i]=save;
    }
    posOdd[l-1]=MAX;
    save=MAX;
    for(int i=s.length()-1;i>=0;i--){
        if(!isOdd(s[i])){
            save=i;
        }
        posEven[i]=save;
    }

    posEven[l-1]=MAX;
    string ans="";
    set<int> has;
    for(int i=0;i<s.length();i++){
        if(has.count(i)>0)
        continue;
        if(isOdd(s[i])){
            save=max(maxiE,posEven[i]);
   //             cout<<i<<" "<<save<<"\n";
            if(save!=-1 && save !=MAX && s[save]<s[i]){
                ans.push_back(s[save]);
                has.insert(save);
                maxiE=posEven[save+1];
                i--;
            }else{
                ans.push_back(s[i]);
                has.insert(i);
            }
        }else{
            save=max(maxiO,posOdd[i]);
    //cout<<i<<" "<<save<<"\n";

            if(save!=-1 && save !=MAX && s[save]<s[i]){
                ans.push_back(s[save]);
                has.insert(save);
                maxiO=posOdd[save+1];
                i--;
            }else{
                ans.push_back(s[i]);
                has.insert(i);
            }
        }
    }

    for(int i=0;i<s.length();i++){
        if(has.count(i)==0){
            ans.push_back(s[i]);
        }
    }

    return ans;
}


int main(){
    int t;
    cin>>t;
    string s;
    for(int i=0;i<t;i++){
        cin>>s;
        cout<<generateSmallest(s)<<"\n";
    }
    return 0;
}
