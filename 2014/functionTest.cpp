#include<iostream>

using namespace std;

float fun();
int main()
{
    int f,k=2.3;
    f=fun();
    cout<<f<<"     "<<k;
    return 0;
}
float fun()
{
    return 10.8;
}
