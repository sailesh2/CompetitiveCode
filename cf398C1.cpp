#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>

#define gc getchar
using namespace std;

vector<int> lamps[1000005];
int breakTemp;
int mainRoot;
int lampTemp[1000005];
int has[1000005]={0};
vector<int> ans;
int gcnt=0;
int breakLamp(int root){
    int sumT=lampTemp[root];
    int next,val;
    for(int i=0;i<lamps[root].size();i++){
        next=lamps[root][i];
        if(has[next]==0){
            has[next]=1;
            val=breakLamp(next);
            sumT=sumT+val;
            has[next]=0;
        }
    }
    if(sumT==breakTemp){

        if(gcnt<2 && root!=mainRoot){
            gcnt++;
            ans.push_back(root);
            return 0;
        } else
            return sumT;
    }
    else
        return sumT;
}


inline int lscan()
{
int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

int main(){
    int n;
    cin>>n;
    int u,t;
    int root;
    int sum=0;
    for(int i=0;i<n;i++){
        u=lscan();
        cin>>t;
        sum=sum+t;
        lampTemp[i+1]=t;
        if(u>0){
            lamps[u].push_back(i+1);
            lamps[i+1].push_back(u);
        } else{
            root=i+1;
        }
    }
    mainRoot=root;


    if(sum%3!=0){
        cout<<"-1";
    } else{
        breakTemp=sum/3;
        has[root]=1;
        int temp=breakLamp(root);
        has[root]=0;
        if(gcnt==2){
            if(ans.size()==2){
                for(int i=0;i<ans.size();i++){
                    cout<<ans[i]<<" ";
                }
            } else{
                cout<<"-1";
            }
        }
        else{
            cout<<"-1";
        }
    }
    return 0;
}
