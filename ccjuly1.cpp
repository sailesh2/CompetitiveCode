#include<iostream>

using namespace std;

int main()
{
    int i,t,j,n;
    long long int ctr;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        ctr=0;
        cin>>n;
        cin>>s;
        for(j=0;j<n;j++)
        {
            if(s[j]=='1')
                ctr++;
        }
        cout<<(ctr*(ctr+1))/2<<"\n";
    }
    return 0;
}
