#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int tr[400][400]={0};
int fl[400][400]={0};
int fun(string s, string op)
{

    int i,j,k,n,l;
    n=s.length();

    for (i = 0; i < n; i++)
    {
        tr[i][i]=(int)s[i]-48;
        fl[i][i]=1-tr[i][i];
    }
    for (l=2; l<=n;l++)
    {
        for (i=0; i<=n-l; i++)
        {
            j=i+l-1;
            for (k=i;k<j;k++)
            {
                int tot1 = tr[i][k] + fl[i][k];
                int tot2 = tr[k+1][j] + fl[k+1][j];

                if (op[k] == 'a')
                {
                    tr[i][j] += tr[i][k]*tr[k+1][j];
                    fl[i][j] += (tot1*tot2 - tr[i][k]*tr[k+1][j]);
                }
                if (op[k] == 'o')
                {
                    fl[i][j] += fl[i][k]*fl[k+1][j];
                    tr[i][j] += (tot1*tot2 - fl[i][k]*fl[k+1][j]);
                }
                if (op[k] == 'x')
                {
                    tr[i][j] += fl[i][k]*tr[k+1][j] + tr[i][k]*fl[k+1][j];
                    fl[i][j] += tr[i][k]*tr[k+1][j] + fl[i][k]*fl[k+1][j];
                }
            }
        }
    }
}
int main()
{
    string s,op,str;
    cin>>s>>op;
    fun(s,op);
    int i,q,l,r;
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>l>>r>>str;
        if(str[0]=='t')
            cout<<tr[l-1][r-1]<<"\n";
        else
            cout<<fl[l-1][r-1]<<"\n";
    }
    return 0;
}
