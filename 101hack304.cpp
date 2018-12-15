#include<stdio.h>
#include<iostream>
#include<set>

using namespace std;

int ctr=0;
int brr[4][4];
set<int> arr[4][4];

void fun(int,int);

int main()
{
    int i,n,j,k,x,posx,posy;
    int has[20]={0};
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cin>>n;
            for(k=0;k<n;k++)
            {
                cin>>x;

                if(has[x]==0)
                {
                    has[x]=1;
                    brr[i][j]=x;
                    if(x==0)
                    {
                        posx=j;
                        posy=k;
                    }
                }
                arr[i][j].insert(x);
            }
        }
    }
    /*for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            cout<<brr[i][j]<<" ";
        cout<<"\n";
    }*/
    fun(posx,posy);
    cout<<ctr;
    return 0;
}
void fun(int x,int y)
{
    int cnt=1;
    int cnt2=0;
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(brr[i][j]!=cnt)
            {
                cnt2=1;
                break;
            }

        cnt=(cnt+1)%16;
        }
        if(cnt2==1)
            break;
    }
    if(cnt2==0)
        ctr++;
    if(x-1>=0)
    {
        if(arr[x-1][y].count(0)>0 && arr[x][y].count(brr[x-1][y])>0)
        {
            brr[x][y]=brr[x-1][y];
            brr[x-1][y]=0;
            fun(x-1,y);
        }
    }
    if(x+1<4)
    {
        if(arr[x+1][y].count(0)>0 && arr[x][y].count(brr[x+1][y])>0)
        {
            brr[x][y]=brr[x+1][y];
            brr[x+1][y]=0;
            fun(x+1,y);
        }
    }
    if(y-1>=0)
    {
        if(arr[x][y-1].count(0)>0 && arr[x][y].count(brr[x][y-1])>0)
        {
            brr[x][y]=brr[x][y-1];
            brr[x][y-1]=0;
            fun(x,y-1);
        }
    }
    if(y+1<4)
    {
        if(arr[x][y+1].count(0)>0 && arr[x][y].count(brr[x][y+1])>0)
        {
            brr[x][y]=brr[x][y+1];
            brr[x][y+1]=0;
            fun(x,y+1);
        }
    }
}
