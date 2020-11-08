#include<bits/stdc++.h>

using namespace std;

int convertToNum(char a){
    return (int)a-48;
}

bool isSameParity(char a, char b){
    int xa=convertToNum(a);
    int xb=convertToNum(b);

    return (a%2==0 && b%2==0) || (a%2!=0 && b%2!=0);
}

string generateSmallest(string s){
    pair<char,int> stk[s.length()];
    int top=-1;
    int rear=-1;
    string ans="";
    set<int> has;
    int j;
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if(top==-1){
            rear=0;
            stk[++top]=make_pair(c,i);
        }else{
            if(isSameParity(stk[top].first,c)){
                while(top>=rear && stk[top].first>c){
                    top--;
                }
                stk[++top]=make_pair(c,i);
            }else{
                for(j=rear;j<=top;j++){
                    if(stk[j].first<c){
                        has.insert(stk[j].second);
                        ans.push_back(stk[j].first);
                    }else{
                        break;
                    }
                }
                rear=j;
                if(rear==top+1){
                    top=0;
                    rear=0;
                    stk[top]=make_pair(c,i);
                }else{
                    has.insert(i);
                    ans.push_back(c);
                }
            }
        }
    }

  //  cout<<"Rear"<<rear<<"TOP"<<top<<"\n";
    for(int i=rear;i<=top;i++){
        if(i==rear){
//            cout<<"s"<<stk[i].second<<"\n";
            for(j=0;j<=stk[i].second;j++){
                if(has.count(j)==0){
                    has.insert(j);
                    ans.push_back(s[j]);
                }
            }
        }
        else if(i==top){
            if(has.count(stk[i].second)==0){
                ans.push_back(stk[i].first);
            }
            break;
        }else{
            for(j=stk[i].second;j<=stk[i+1].second;j++){
                if(has.count(j)==0){
                    has.insert(j);
                    ans.push_back(s[j]);
                }
            }
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
