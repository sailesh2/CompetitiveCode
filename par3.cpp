#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main()
{
    int i,t,n,m,j,k,x,r,c,dif,save,save2,cnt,ctr;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cnt=0;
        ctr=0;
        save=-1;
        cin>>n>>m;
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                cin>>x;
                if(x!=0)
                {
                    r=(int)ceil((float)x/m)-1;
                    c=x%m-1;
             //       cout<<r<<"c"<<c<<"\n";
                    if(c<0)
                        c=m+c;
                    dif=abs(r-j)+abs(c-k);
                    if(dif!=0)
                    {
                        if(save==-1)
                        {
                            ctr++;
                            save=dif;
                            save2=x;
                        }
                        else
                        {
                            if(dif!=save)
                                cnt=1;
                            else
                                ctr++;
                        }
                    }
                }
            }
        }
        if(cnt==0)
        {
            if(ctr==1)
            {
                if(save2==(n-1)*m || save2==(n*m)-1)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
            else
                cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }
    return 0;
}
