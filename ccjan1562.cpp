#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    long long int i,n,q,x,y,z;
    long long int sumz,sumo,sumt,sum,cntz,cnto,cntt;
    string str;
    cin>>n>>q;
    long long int arr[n],zero[n],one[n],two[n];
    sumz=0;
    sumo=0;
    sumt=0;
    cin>>str;
    for(i=0;i<n;i++)
    {
        arr[i]=(int)str[i]-48;
        if(i!=0)
            arr[i]=(arr[i]+arr[i-1])%3;
        if(arr[i]==0)
            sumz++;
        else if(arr[i]==1)
            sumo++;
        else
            sumt++;
        zero[i]=sumz;
        one[i]=sumo;
        two[i]=sumt;
    }
    for(i=0;i<q;i++)
    {
        cin>>x>>y>>z;
        if(x==2)
        {
            y--;
            z--;
            if(y!=0)
                sum=arr[y-1];
            else
                sum=0;
            cntz=sum%3;
            cnto=(sum+1)%3;
            cntt=(sum+2)%3;

            if(cntz==0)
            {
                if(y!=0)
                    sumz=zero[z]-zero[y-1];
                else
                    sumz=zero[z];
            }
            else if(cntz==1)
            {
                if(y!=0)
                    sumz=one[z]-one[y-1];
                else
                    sumz=one[z];
            }
            else
            {
                if(y!=0)
                    sumz=two[z]-two[y-1];
                else
                    sumz=two[z];
            }

            if(cnto==0)
            {
                if(y!=0)
                    sumo=zero[z]-zero[y-1];
                else
                    sumo=zero[z];
            }
            else if(cnto==1)
            {
                if(y!=0)
                    sumo=one[z]-one[y-1];
                else
                    sumo=one[z];
            }
            else
            {
                if(y!=0)
                    sumo=two[z]-two[y-1];
                else
                    sumo=two[z];
            }

            if(cntt==0)
            {
                if(y!=0)
                    sumt=zero[z]-zero[y-1];
                else
                    sumt=zero[z];
            }
            else if(cntt==1)
            {
                if(y!=0)
                    sumt=one[z]-one[y-1];
                else
                    sumt=one[z];
            }
            else
            {
                if(y!=0)
                    sumt=two[z]-two[y-1];
                else
                    sumt=two[z];
            }

            cout<<(sumz*(sumz+1))/2+(sumo*(sumo-1))/2+(sumt+(sumt-1))/2<<"\n";
        }
        else
        {

        }
    }
    return 0;
}
