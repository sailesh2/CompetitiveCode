#include<stdio.h>
#include<iostream>
#include<set>
#include<iterator>

using namespace std;

int maxi,save,has[20];
  set<int> prime;
void fun(int*,int,int,int,int*);

int main()
{
    int i,t,j,n,num1,num2,ctr;

    for(i=2;i<=8000;i++)
    {
        ctr=0;
        for(j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                num1=j;
                num2=i/j;
                if(num1==num2)
                    ctr++;
                else
                    ctr=ctr+2;
            }
        }

            if(ctr==2)
                prime.insert(i);
    }
    int ans[8100]={0};
    ans[2]=1;
    ans[3]=1;
    ans[5]=1;
    ans[7]=1;
    for(i=9;i<=8005;i=i+2)
    {
        int bin[20]={0};
        int emp[20]={0};
        for(j=0;j<20;j++)
            has[j]=0;
        ctr=0;
        set<int> st;
        if(prime.count(i)==0)
        {
            num1=i;
            while(num1>0)
            {
                num2=num1%2;
                bin[ctr++]=num2;
                num1=num1/2;
            }
            for(j=0;j<ctr;j++)
            {
               if(bin[j]==1)
               {
                   if(has[j]==0)
                   {
                       maxi=0;
                       save=-1;
                       has[j]=1;
                       fun(bin,j,0,ctr,emp);
                       if(save==-1)
                            break;
                       st.insert(save);
                       num1=save;
                       int ctr2=0;
                        while(num1>0)
                        {
                            num2=num1%2;
                            if(num2==1)
                                has[ctr2]=1;
                            num1=num1/2;
                            ctr2++;
                        }
                   }
               }
            }
            if(save!=-1)
            {
            //set<int>::iterator it;
            if(st.size()<=4)
            {
              //  cout<<i<<"\n";
                //for(it=st.begin();it!=st.end();it++)
                  //  cout<<*it<<" ";
                //cout<<"\n";
                ans[i]=1;
            }
            }
            else
                ans[i]=0;
        }
        else
            ans[i]=1;
    }
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        if(ans[n]==0)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}
void fun(int * bin,int fixed,int pos,int fin,int *emp)
{
    if(pos==fin)
    {
        int i,cnt=0,num=0,p2=1;
        for(i=0;i<fin;i++)
        {
            if(has[i]==0 && bin[i]==1)
            {
                if(emp[i]==1)
                    cnt++;
            }
            num=num+p2*emp[i];
            p2=p2*2;
        }
        if(prime.count(num)>0)
        {
        if(cnt>=maxi)
        {
            maxi=cnt;
            save=num;
        }
        }
        return;
    }
    if(bin[pos]==0)
    {
        emp[pos]=0;
        fun(bin,fixed,pos+1,fin,emp);
    }
    else
    {
        if(pos==fixed)
        {
            emp[pos]=1;
            fun(bin,fixed,pos+1,fin,emp);
        }
        else
        {
            emp[pos]=0;
            fun(bin,fixed,pos+1,fin,emp);

            emp[pos]=1;
            fun(bin,fixed,pos+1,fin,emp);
        }
    }
}

