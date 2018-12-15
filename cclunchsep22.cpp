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
        int sav[1000001]={0};
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
                    if(num%((int)(pow(2,sav[2]+1)))!=0)
                        break;
                    ctr++;
                    sav[2]++;
                    num = num/2;
                }
                for (l = 3; l <= sqrt(num); l = l+2)
                {
                    while (num%l == 0)
                    {
                        if(num%(((int)pow(l,sav[l]+1)))!=0)
                            break;
                        sav[l]++;
                        num = num/l;
                    }
                }

                if (num > 2)
                {
                    if(sav[num]==0)
                    {
                        sav[num]=1;
                        ctr++;
                    }
                }
            }
        }
        cout<<ctr<<"\n";
    }
    return 0;
}

