#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

struct c
{
    int i;
    char j;
};

bool fun(struct c a,struct c b)
{
    return (a.i>b.i);
}
int main()
{
    struct c arr[3];
    arr[0].i=10;
    arr[0].j='B';

    arr[1].i=1;
    arr[1].j='A';

    arr[2].i=14;
    arr[2].j='C';
    sort(arr,arr+3,fun);
    for(int i=0;i<3;i++)
    {
        cout<<arr[i].i<<" "<<arr[i].j<<"\n";
    }
    cout<<"\n";
    return 0;
}
