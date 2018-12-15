#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,x,mini,save,save2;
    cin>>n;
    mini=1000000005;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(i==n/2)
            save2=x;
        if(i<n/2)
        {
            if(x<=mini)
            {
                mini=x;
                save=i;
            }
        }
    }
    if(mini<save2)
    {
        cout<<"1\n";
        cout<<save+1<<" "<<n<<"\n";
    }
    else
        cout<<"0\n";
    return 0;
}
