#include<stdio.h>
#include<iostream>

using namespace std;



int main()
{

    int i,t,j,n,m,save,maxi,mini,val,cols;
    char x;
    long long int p;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        p=1;
        scanf("%d%d",&n,&m);
        int has[100001]={0};
        maxi=0;
        mini=1000000;
        for(j=0;j<m;j++)
        {
            cin>>x>>val;
            if(j==0)
                cols=(int)x;
            else
            {
                if(cols!=(int)x)
                    cols=-1;
            }
            if(val>=maxi)
                maxi=val;
            if(val<=mini)
                mini=val;
            has[val-1]=(int)x;
        }
        if(m==1 || cols!=-1)
            printf("1\n");
        else if(m==2)
        {
            printf("%d\n",maxi-mini);
        }
        else
        {
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
                            p=((p%1000000009)*(j-save)%1000000009)%1000000009;
                        save=j;
                    }
                }
            }
        printf("%lld\n",p);
        }
    }
    return 0;
}
