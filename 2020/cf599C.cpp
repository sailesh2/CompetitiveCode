#include<bits/stdc++.h>

using namespace std;




pair<bool,vector<pair<int,int> > > minimumSwap(string s1, string s2) {
    int l=s1.length();
    int cnt=0;
    pair<bool,vector<pair<int,int> > > ans;
    vector<pair<int,int> > v;
    for(int i=0;i<l;i++){
        if(s1[i]!=s2[i]){
            for(int j=i+1;j<l;j++){
                if(s1[j]==s1[i] && s1[j]!=s2[j]){
                    char temp=s1[j];
                    s1[j]=s2[i];
                    s2[i]=temp;
                    cnt++;
                    v.push_back(make_pair(j,i));
                    break;
                }
            }
        }
        if(s1[i]!=s2[i]){
            for(int j=i+1;j<l;j++){
                if(s2[j]==s2[i] && s1[j]!=s2[j]){
                    char temp=s2[j];
                    s2[j]=s1[i];
                    s1[i]=temp;
                    cnt++;

                    v.push_back(make_pair(i,j));
                    break;
                }
            }
        }
        if(s1[i]!=s2[i]){
            for(int j=i+1;j<l;j++){
                if(s2[j]==s1[i] && s1[j]!=s2[j]){
                    char temp=s2[j];
                    s2[j]=s1[j];
                    s1[j]=temp;

                    v.push_back(make_pair(j,j));

                    temp=s1[j];
                    s1[j]=s2[i];
                    s2[i]=temp;

                    cnt=cnt+2;

                    v.push_back(make_pair(j,i));
                    break;
                }
            }
        }

        if(s1[i]!=s2[i] || cnt>2*l)
            return make_pair(false,v);
    }

    return make_pair(true,v);
}

int main(){
    int q,n;
    cin>>q;
    string s,t;
    for(int i=0;i<q;i++){
        cin>>n;
        cin>>s>>t;
        pair<bool,vector<pair<int,int> > > ans = minimumSwap(s,t);
        if(ans.first){
            cout<<"Yes\n";
            cout<<ans.second.size()<<"\n";
            for(int j=0;j<ans.second.size();j++){
                cout<<1+ans.second[j].first<<" "<<1+ans.second[j].second<<"\n";
            }
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}
