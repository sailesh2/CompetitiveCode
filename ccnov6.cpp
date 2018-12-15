#include<stdio.h>
#include<iostream>
#include<string.h>
#include<set>

using namespace std;

int main()
{
    double arr[26][26]={0};
    double ans[26][26]={0};
    double p[26][26]={0};
    double p1[26][26]={0};

    int i,t,j,n,k,l,ctr,a,b,c,len;
    string str,s;
    double prod,sm;
    cin>>t;
    //cout<<t;
    for(i=0;i<t;i++)
    {
        set<string> st;
        cin>>n>>k;
        cin>>str;
        //cout<<n;
        for(j=0;j<26;j++)
        {
            for(l=0;l<26;l++)
                cin>>arr[j][l];
        }
        int bin[100],ctr=0;
        while(k!=0)
        {
            bin[ctr]=k%2;
            k=k/2;
            ctr++;
        }

       double ans[26][26]={0};
        for(j=0;j<26;j++)
        {
            for(l=0;l<26;l++)
                {
                    p[j][l]=arr[j][l];
                    if(bin[0]==1)
                        ans[j][l]=arr[j][l];
                    else
                    {
                        if(j==l)
                            ans[j][l]=1;
                    }
                }
        }
        j=1;
        while(j<ctr)
        {
            for(a=0;a<26;a++)
            {
                for(b=0;b<26;b++)
                {
                    sm=0.0;
                    for(c=0;c<26;c++)
                    {
                        sm=sm+p[a][c]*p[c][b];
                    }
                    p1[a][b]=sm;
                }
            }
            for(a=0;a<26;a++)
            {
                for(b=0;b<26;b++)
                    p[a][b]=p1[a][b];
            }
            if(bin[j]==1)
            {
                for(a=0;a<26;a++)
                {
                    for(b=0;b<26;b++)
                    {
                        sm=0.0;
                        for(c=0;c<26;c++)
                        {
                            sm=sm+ans[a][c]*p[c][b];
                        }
                        p1[a][b]=sm;
                    }
                }
                for(a=0;a<26;a++)
                {
                    for(b=0;b<26;b++)
                        ans[a][b]=p1[a][b];
                }
            }
            j++;
        }
        sm=0.0;

        for(j=0;j<n;j++)
        {
            cin>>s;
            if(st.count(s)==0)
            {
                if((len=s.length())==str.length())
                {
                    prod=1;
                    for(l=0;l<len;l++)
                        prod=prod*ans[str[l]-'a'][s[l]-'a'];
             //       cout<<prod<<"\n";
                    sm=sm+prod;
                }
                st.insert(s);
            }
        }
        printf("%.15lf\n",sm);
    }
    return 0;
}
