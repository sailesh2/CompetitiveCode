#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,j,minw=100,minb=100,k,ctr,cnt;
    string s;
    char chess[8][8];
    for(i=0;i<8;i++)
    {
        cin>>s;
        for(j=0;j<8;j++)
            chess[i][j]=s[j];
    }
    /*for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            cout<<chess[i][j];
        cout<<"\n";
    }*/
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(chess[i][j]=='W')
            {
                ctr=0;
                cnt=0;
                for(k=i-1;k>=0;k--)
                {
                    if(chess[k][j]=='.')
                        ctr++;
                    else
                    {
                        cnt=1;
                        break;
                    }
                }
                if(cnt==0)
                    minw=min(minw,ctr);
            }
            else if(chess[i][j]=='B')
            {
                ctr=0;
                cnt=0;
                for(k=i+1;k<8;k++)
                {
                    if(chess[k][j]=='.')
                        ctr++;
                    else
                    {
                        cnt=1;
                        break;
                    }
                }
               // cout<<ctr<<" "<<i<<" "<<j<<"\n";
                if(cnt==0)
                    minb=min(minb,ctr);
            }
        }
    }
    //cout<<minb<<" "<<minw;
    if(minb<minw)
        cout<<"B";
    else
        cout<<"A";
    return 0;
}
