#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>

using namespace std;
int has[200005]={0};
int gval[200005];
int ans[200005]={0};
vector<int> tree[200005];
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

void findGCD(int ind,int maxGCD,int max2, int currGCD){
    int next;
    int maxi;
    int nextCurrGCD;
    nextCurrGCD=gcd(currGCD,gval[ind]);

    maxi=max(gcd(maxGCD,gval[ind]),currGCD);
    maxi=max(gcd(max2,gval[ind]),maxi);

    ans[ind]=max(maxi,ans[ind]);

    for(int i=0;i<tree[ind].size();i++){
        next=tree[ind][i];
        if(has[next]==0){
            has[next]=1;
            findGCD(next,ans[ind],currGCD,nextCurrGCD);
            has[next]=0;
        }
    }
}

int main(){
    int n,u,v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>gval[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        tree[u-1].push_back(v-1);

        tree[v-1].push_back(u-1);
    }
    if(n==1){
        cout<<gval[0];
    } else
    {


        has[0]=1;
        findGCD(0,gval[0],0,gval[0]);
        has[0]=0;


        has[0]=1;
        gval[0]=0;
        findGCD(0,gval[0],0,gval[0]);
        has[0]=0;

        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}
