#include<stdio.h>
#include<iostream>
#include<vector>


using namespace std;

long long int sm=0;
pair<int,int> fun(vector<int> *,int,int *);
int main()
{
    int i,t,j,n,x,y;
    cin>>t;
    pair<int,int> pr;
    for(i=0;i<t;i++)
    {
        sm=0;
        int has[100000]={0};
        cin>>n;
        vector<int> arr[n+1];
        for(j=0;j<n-1;j++)
        {
            cin>>x>>y;
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        has[1]=1;
        pr=fun(arr,1,has);
        has[1]=0;
        cout<<sm<<"\n";
    }
}
pair<int,int> fun(vector<int> * arr,int pos,int * has)
{
    //cout<<pos<<"\n";
    pair<int,int> pr;
    int i,k=0,ev=0,od=0,evarr[1000],odarr[1000],sm_evarr[1000],sm_odarr[1000];
    for(i=0;i<arr[pos].size();i++)
    {
     //   cout<<arr[pos][i]<<" - ";
        if(has[arr[pos][i]]==0)
        {
       //     cout<<"r";
            has[arr[pos][i]]=1;
            pr=fun(arr,arr[pos][i],has);
            od=od+pr.first;
            odarr[k]=pr.first;
            ev=ev+pr.second;
            evarr[k]=pr.second;
            k++;

            has[arr[pos][i]]=0;
        }
    }
    //cout<<pos<<" "<<ev<<" "<<od<<"\n";


    //cout<<"\n";
    sm=sm+ev;
    if(k>0)
    {
    sm_odarr[k-1]=odarr[k-1];
    sm_evarr[k-1]=evarr[k-1];
    for(i=k-2;i>=0;i--)
    {
        sm_odarr[i]=sm_odarr[i+1]+odarr[i];
        sm_evarr[i]=sm_evarr[i+1]+evarr[i];
    }
    for(i=0;i<k-1;i++)
    {
        sm=sm+odarr[i]*sm_odarr[i+1];
        sm=sm+evarr[i]*sm_evarr[i+1];
    }
    }
//    pr.first=ev;
//    pr.second=od;
        pr=(make_pair(ev+1,od));
    return pr;
}
