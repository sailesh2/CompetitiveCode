#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int area[11];
    int i,j,d,s,p,save,mini=10000000;
    for(i=1;i<11;i++)
    {
        cin>>area[i];
    }
    for(d=1;d<11;d=d+2)
    {
        s=0;
        p=1;
        j=d;
        for(i=1;i<10;i++)
        {
            s=s+area[j]*p;
            if(j+3==10)
                j=10;
            else
                j=(j+3)%10;
            p=p*2;
        }
        if(s<mini)
            save=d;
    }
    for(i=1;i<10;i++)
    {
        cout<<area[save]<<" ";
        if(save+3==10)
                save=10;
        else
                save=(save+3)%10;
    }
    return 0;
}
