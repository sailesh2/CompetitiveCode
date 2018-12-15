#include<stdio.h>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

double sm=0;
long long int ctr=0;

vector<int> arr[1000005];
int has[1000005]={0};
void travel(int,long long int,double);

int main(){
    int n,u,v;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    if(n>1){
    has[1]=1;
    travel(1,0,1);
    has[1]=0;
    }
    if(ctr==0 || n==1)
        cout<<"0.000000000000000";
    else
        printf("%.15lf",sm);
    return 0;
}

void travel(int index,long long int sum ,double p){
    int node,cnt=0;
    double p1;
    for(int i=0;i<arr[index].size();i++){
        node=arr[index].at(i);
        if(has[node]==0){
            cnt=1;
            has[node]=1;
            if(index==1)
            p1 = p*((double)1/(arr[index].size()));
            else
                p1 = p*((double)1/(arr[index].size()-1));
            travel(node,sum+1,p1);
            has[node]=0;
        }
    }

   if(cnt==0){
        sm=sm+(double)sum*p;
        ctr++;
    }
}
