#include<iostream>

using namespace std;

int main()
{
    int i,j,t,l,n,m,k;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m>>k;
        for(j=0;j<n;j++)
        {
            for(l=0;l<m;l++)
            {
                cout<<'A';
            }
            cout<<"\n";
        }
    }
    return 0;
}
