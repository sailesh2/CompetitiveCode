#include<stdio.h>
#include<iostream>
#define gc getchar


using namespace std;



void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc())
        {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{

    int i,t,j,n,m,save,maxi,mini;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        int val;
        int has[100001]={0};
        char x;
        long long int p=1;
        maxi=0;
        mini=1000000;
        for(j=0;j<m;j++)
        {
            cin>>x;
            scanint(val);
            //cout<<x;
            //cin>>x>>val;
            if(val>=maxi)
                maxi=val;
            if(val<=mini)
                mini=val;
            has[val-1]=(int)x;
        }
            save=-1;
            for(j=mini-1;j<maxi;j++)
            {
                if(has[j]>0)
                {
                    if(save==-1)
                        save=j;
                    else
                    {
                        if(has[j]!=has[save])
                        {
              //              cout<<j<<"  "<<save<<" "<<has[j]<<" "<<has[save]<<"\n";
                            p=((p%1000000009)*(j-save)%1000000009)%1000000009;
                        }
                        save=j;
                    }
                }
            }

        cout<<p<<"\n";
    }
    return 0;
}
