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
vector<pair<int,int> > po;

void postOrder(int root){

    int next;
    for(int i=0;i<lamps[root].size();i++)
    {
        next=lamps[root][i];
        if(has[next]==0){
            has[next]=1;
            postOrder(next);
            has[next]=0;
        }
    }
    po.push_back(make_pair(lampTemp[root],root));

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
        t=lscan();
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
        postOrder(root);
        has[root]=0;
//        po.push_back(make_pair(lampTemp[root],root));
        int cnt=0,sumT=0,sumT1=0;
        for(int i=0;i<po.size();i++){
            sumT=sumT+po[i].first;
            if(sumT==breakTemp){
                if(sum-sumT==2*breakTemp){
                    if(po[i].second!=root){
                    ans.push_back(po[i].second);
                    cnt++;
                    if(cnt==2)
                        break;
                    sumT=0;
                    }
                }
            }
        }

        if(cnt==2){
            cout<<ans[0]<<" "<<ans[1];
        } else{
            cout<<"-1";
        }
    }
    return 0;
}
