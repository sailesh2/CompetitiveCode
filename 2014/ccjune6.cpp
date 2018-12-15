#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    long long int i,t,n,j,sm,q,k,x,p,save,save1,ctr,power,power_save,p1;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>q;
        long long int arr[n];
        for(j=0;j<n;j++)
        {
            cin>>x;
            if(j==0)
                arr[j]=x;
            else
                arr[j]=arr[j-1]+x;
        }
        for(k=0;k<q;k++)
        {
            cin>>x;
            sm=0;
            for(j=0;j<n;j++)
            {
                p1=pow(x,(float)1/(j+1));
                p=pow(p1,j+1);
                if(p==x)
                {
                    if(j==0)
                        sm=sm+(p1*arr[j])%1000000007;
                    else
                        sm=sm+(p1*(arr[j]-arr[j-1]))%1000000007;
                }
                else
                {
					power=p1;
					power_save=p;
                    save=j;
                    ctr=1;
                    save1=save;
                    while(save+ctr<n)
                    {
                        if(p*power<=x)
                        {
                            save1=save+ctr;
                            ctr=ctr*2;
                            power_save=p*power;
                            power=(power*power);
                        }
                        else
                        {
                            if(save+ctr==save1+1)
                                break;
                            save=save1;
                            ctr=1;
                            p=power_save;
                            power=p1;
                        }
                    }
                    if(j==0)
                        sm=sm+(p1*arr[save1])%1000000007;
                    else
                        sm=sm+(p1*(arr[save1]-arr[j-1]))%1000000007;
                    j=save1;
            	}
        	}
        	cout<<sm%1000000007<<" ";
    	}
    	cout<<"\n";
	}
return 0;
}
