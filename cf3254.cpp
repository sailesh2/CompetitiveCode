#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,j,n,l,stx,sty,k,save,save1,save2,savestx,savesty,cnt,ans;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cnt=1;
        cin>>n>>k;
        char arr[3][n];
        for(j=0;j<3;j++)
        {
            for(k=0;k<n;k++)
            {
                cin>>arr[j][k];
            }
        }

        sty=0;
        if(arr[0][0]=='s')
        {
            stx=0;
        }
        if(arr[1][0]=='s')
        {
            stx=1;
        }
        if(arr[2][0]=='s')
        {
            stx=2;
        }
        while(sty!=n-1)
        {


            if(arr[stx][sty]!='s' && arr[stx][sty]!='.')
            {
                cnt=0;
                break;
            }
            savestx=stx;
            savesty=sty;
            sty++;

           if(arr[stx][sty]!='s' && arr[stx][sty]!='.')
            {
                cnt=0;
                break;
            }
            save=-1;
            if(stx+1<3)
            {
            for(j=sty;j<n;j++)
            {
                if(arr[stx+1][j]!='.')
                {
                    save=j;
                    break;
                }
            }
            if(save==-1)
            {
                cnt=1;
                break;
            }
            }

            save1=-1;
            if(stx-1>=0)
            {
            for(j=sty;j<n;j++)
            {
                if(arr[stx-1][j]!='.')
                {
                    save1=j;
                    break;
                }
            }
            if(save1==-1)
            {
                cnt=1;
                break;
            }
            }
            if(save==-1)
            {
                ans=stx-1;
            }
            else if(save1==-1)
            {
                ans=stx+1;
            }
            else
            {
                if(save>=save1)
                    ans=stx+1;
                else
                    ans=stx-1;
            }



            save2=-1;

            for(j=sty;j<n;j++)
            {
                if(arr[stx][j]!='.')
                {
                    save2=j;
                    break;
                }
            }
            if(save2==-1)
            {
                cnt=1;
                break;
            }

            if(save2<max(save,save1))
            {
                stx=ans;
            }
            if(arr[stx][sty]!='s' && arr[stx][sty]!='.')
            {
                cnt=0;
                break;
            }
            arr[stx][sty]='s';
            arr[savestx][savesty]='.';
            for(j=0;j<3;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(arr[j][k]!='.' && arr[j][k]!='s')
                    {
                        if(k-1>=0)
                        arr[j][k-1]=arr[j][k];
                        if(k-2>=0)
                        arr[j][k-2]=arr[j][k];
                        for(l=k;l<n;l++)
                        {
                            if(arr[j][l]=='.')
                            {
                                if(l-1>=0)
                                arr[j][l-1]='.';
                                if(l-2>=0)
                                arr[j][l-2]='.';

                                k=l;
                                break;
                            }
                        }
                        if(l==n)
                        {
                            arr[j][l-1]='.';
                            arr[j][l-2]='.';
                            break;
                        }
                    }
                }
            }
            if(arr[stx][sty]!='s' && arr[stx][sty]!='.')
            {
                cnt=0;
                break;
            }

        }
        if(cnt==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
