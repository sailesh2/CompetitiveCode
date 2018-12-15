#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

long long int sm;
int num1,num2;
int n,m;
void fun(int,int,int *,int *);

int main()
{
    int i,j,t;
    string str1,str2;
    cin>>t;
    for(i=0;i<t;i++)
    {
        sm=0;
        cin>>n>>m;
        cin>>str1>>str2;
        num1=0;
        num2=0;
        for(j=0;j<m;j++)
            num1=((int)str1[j]-65)+num1*2;
        for(j=0;j<m;j++)
            num2=((int)str2[j]-65)+num2*2;


        int arr[n],has[1001]={0};
        fun(0,0,arr,has);
        cout<<"                "<<(sm);
    }
    return 0;
}
void fun(int i,int num,int *arr,int *has)
{


    if(i==n)
    {
         cout<<i<<" "<<num<<" ";
        int j,k;
        long long int num3=0;
        if(has[num]==1)
        {
            return;
        }
        for(k=0;k<m-1;k++)
        {
            num3=num3*2+arr[k];
        }
        for(j=0;j<=n-m;j++,k++)
        {
            num3=num3*2+arr[k];
            if(num3>=num1 && num3<=num2)
            {
                has[num]=1;
                return;
            }
            num3=(num3/2);
        }
        has[num]=1;
        sm=(sm+1)%1000000007;
        return;
    }
    arr[i]=0;
    fun(i+1,num*2,arr,has);
    arr[i]=1;
    fun(i+1,num*2+1,arr,has);
}
