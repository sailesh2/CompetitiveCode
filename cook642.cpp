#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,j,n,k,ln,save,dis;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        int arr[n];
        for(j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        int brr[n];
        ln=0;
        dis=0;
        for(j=0;j<n;j++)
        {
            save=-1;
            for(k=0;k<ln;k++)
            {
                if(brr[k]==arr[j])
                {
                    save=k;
                    break;
                }
            }
            if(save==-1)
            {
                for(k=ln-1;k>=0;k--)
                    brr[k+1]=brr[k];
                brr[0]=j+1;

            }
            else
            {
                for(k=ln-1;k>save;k--)
                    brr[k+1]=brr[k];
                brr[save+1]=j+1;
                dis=dis+min(ln-save-1,save+1);
            }
            ln++;
        }
        cout<<dis<<"\n";
    }
    return 0;
}
