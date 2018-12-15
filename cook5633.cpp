#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

int m;
int arr[20];
long long int num1,num2,sum2;

int fun(int,int,int *);

int main()
{
    int i,n,t,j,k;
    string str2,str1;
    cin>>t;
    for(i=0;i<t;i++)
    {
        sum2=0;
        cin>>n>>m;
        cin>>str1>>str2;
        num1=0;
        num2=0;
        k=1;
        for(j=m-1;j>=0;j--)
        {
            num1=((int)str1[j]-65)*k+num1;
            k=k*2;
        }
        k=1;
        for(j=m-1;j>=0;j--)
        {
            num2=((int)str2[j]-65)*k+num2;
            k=k*2;
        }
        int dp[n];
        int power=26;
        for(j=0;j<n;j++)
        {
            if(j<m-1)
                dp[j]=power;
            else
                dp[j]=-1;
            power=(power*26)%1000000007;
            //cout<<dp[j];
        }
        for(j=m-1;j<n;j++)
            dp[j]=fun(0,j+1,dp)%1000000007;
        cout<<dp[n-1]%1000000007<<"\n";
        //cout<<sum2<<"\n";
    }
    return 0;
}
int fun(int i,int n,int *dp)
{
    //cout<<i<<" "<<n<<"\n";
    if(i==n)
    {
        sum2++;
        //cout<<sum2;
        return 1;
    }
    int j,k,cnt,l;
    long long int num,save,sm=0;

    cnt=0;
    num=0;
    save=num;
    if(i>=m-1)
    {
        for(k=i-m+1;k<i;k++)
        {
            if(arr[k]!=0 && arr[k]!=1)
            {
                cnt=1;
                break;
            }
            num=arr[k]+num*2;
            save=num;
        }
    }
    else
        cnt=1;

    for(j=0;j<26;j++)
    {
        arr[i]=j;
        num=num*2+arr[i];
        if(arr[i]!=0 && arr[i]!=1)
            cnt=1;
        if(cnt==0)
        {
            if(num>=num1 && num<=num2)
            {
                num=save;
                continue;
            }
            else
            {
                num=save;
      //          cout<<"f";
                sm=sm+fun(i+1,n,dp);
            }
        }
        else
        {
            if(arr[i]==0 || arr[i]==1)
            {
        //        cout<<"g";
                sm=sm+fun(i+1,n,dp);
            }
            else
            {
                if(n-(i+2)<0)
                    sm=sm+1;
                else
                {
                    if(dp[n-(i+2)]!=-1)
                        sm=sm+dp[n-(i+2)];
                }
            }
    //        else
      //          sm=sm+fun(0,n-(i+1),dp);
            num=save;
        }
        //cout<<sm<<"vds\n";
    }
    //cout<<sm<<"ki";
    sm=sm%1000000007;
    //dp[n-i-1]=sm;
    return sm;
}
