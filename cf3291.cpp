#include<stdio.h>
#include<iostream>
#include<string.h>
#include<map>

using namespace std;

int main()
{
    int i,n,j,ctr;
    cin>>n;
    string s;
    long long int maxi=0;
    long long int mp[300][300]={0};
    char chara,charb;
    for(i=0;i<n;i++)
    {
        cin>>s;
        ctr=0;
        int has[300]={0};


        for(j=0;j<s.length();j++)
        {
            if(has[(int)s[j]]==0)
            {
                ctr++;
                if(ctr==3)
                    break;
                if(ctr==1)
                {
                    chara=s[j];
                    charb=s[j];
                }
                else
                    charb=s[j];
            }
            has[(int)s[j]]=1;

        }
        //cout<<chara<<" "<<charb<<" "<<ctr<<"\n";
        if(ctr<3)
        {
            mp[(int)chara][(int)charb]=mp[(int)chara][(int)charb]+s.length();
            if(chara!=charb)
            mp[(int)charb][(int)chara]=mp[(int)charb][(int)chara]+s.length();
        }
    }
    //cout<<mp[(int)'b'][(int)'b'];
    for(i=(int)'a';i<=(int)'z';i++)
    {
        for(j=i+1;j<=(int)'z';j++)
        {
            //cout<<mp[i][j]<<" ";
            if((mp[i][j]+mp[i][i]+mp[j][j])>maxi)
            {
      //          cout<<(char)i<<" "<<(char)j;
                maxi=(mp[i][j]+mp[i][i]+mp[j][j]);
            }
        }
    }
    for(i=(int)'a';i<=(int)'z';i++)
    {
        for(j=i+1;j<=(int)'z';j++)
        {
            if(mp[i][i]+mp[j][j]>maxi)
                maxi=mp[i][i]+mp[j][j];
        }
    }
    for(i=(int)'a';i<=(int)'z';i++)
    {
        if(mp[i][i]>maxi)
            maxi=mp[i][i];
    }
    cout<<maxi;
    return 0;
}
