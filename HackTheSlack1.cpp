#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n;
    while(1)
    {
        cin>>n;
        if(n==-1)
            break;
        if(n%2==0)
            cout<<n<<"\n";
    }
    return 0;
}
