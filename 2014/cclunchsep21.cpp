#include<stdio.h>
#include<iostream>
#import<math.h>

using namespace std;

int main()
{
    int i,t,j,k,l,ctr,num,n;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        int arr[n];
        for(j=0;j<n;j++)
            cin>>arr[j];
        ctr=0;
        for(j=0;j<n;j++)
        {
            if(arr[j]!=1)
            {
                num=arr[j];
                while (num%2 == 0)
                {
                    ctr++;
                    for(k=j;k<n;k++)
                    {
                        if(arr[k]%2==0)
                            arr[k]=arr[k]/2;
                    }
                    num = num/2;
                }
                for (l = 3; l <= sqrt(num); l = l+2)
                {
                    while (num%l == 0)
                    {
                        ctr++;
                        for(k=j;k<n;k++)
                        {
                            if(arr[k]%l==0)
                                arr[k]=arr[k]/l;
                        }
                        num = num/l;
                    }
                }

                if (num > 2)
                {
                    ctr++;
                    for(k=j;k<n;k++)
                    {
                        if(arr[k]%num==0)
                            arr[k]=arr[k]/num;
                    }
                }
            }
        }
        cout<<ctr<<"\n";
    }
    return 0;
}
