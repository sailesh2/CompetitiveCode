#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,k;
    int maxi=-2000,maxi3,save2,save3,temp,j,cnt;
    cin>>n>>k;
    int arr[n];
    int has[2000]={0};
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>maxi)
            maxi=arr[i];
    }
    if(maxi<=0)
        cout<<maxi;
    else
    {
        int sm=0;
        int brr[n],l=0;
        for(i=0;i<n;i++)
        {
          //  cout<<sm<<"\n";
            if(arr[i]<0)
            {
                brr[l]=sm;
                l++;
                brr[l]=arr[i];
                l++;
                sm=0;
            }
            else
            {
                sm=sm+arr[i];
            }
        }
        if(sm>0)
        {
            brr[l]=sm;
            l++;
        }
        if(l==0)
            cout<<sm;
        else
        {
                    for(i=0;i<l;i++)
                        cout<<brr[i]<<" ";
                    int maxi2=-2,save=-1;
                    for(i=0;i<l;i++)
                    {
                        if(brr[i]>maxi2)
                        {
                            maxi2=brr[i];
                            save=i;
                        }
                    }
                    for(i=0;i<k;i++)
                    {
                        j=save;
                        cnt=0;
                        while(j<l)
                        {
                            if(brr[j]<0)
                            {
                                cnt=1;
                                break;
                            }
                            else
                                has[j]=1;
                            j++;
                        }
                        if(cnt==0)
                        {
                            j=save;
                            while(j>=0)
                            {
                                if(brr[j]<0)
                                {
                                    cnt=1;
                                    break;
                                }
                                else
                                    has[j]=1;
                                j--;
                            }
                        }
                        if(cnt==0)
                            break;
                        else
                        {
                            save2=j;
                            maxi3=-2000;
                            for(j=0;j<l;j++)
                            {
                                if(has[j]==0)
                                {
                                    if(brr[j]>maxi3)
                                    {
                                        maxi3=brr[j];
                                        save3=j;
                                    }
                                }
                            }
                            if(maxi3>brr[save2])
                            {
                                temp=brr[save3];
                                brr[save3]=brr[save2];
                                brr[save2]=temp;
                            }
                        }
                    }
                    sm=0;
                    maxi=-1;
                    for(i=0;i<l;i++)
                    {
                        //cout<<brr[i]<<" ";
                        sm=sm+brr[i];
                        if(sm<0)
                            sm=0;
                        if(sm>maxi)
                            maxi=sm;
                    }
                    cout<<"\n"<<maxi;
        }
    }
    return 0;
}
