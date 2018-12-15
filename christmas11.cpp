#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    float pie=3.1416;
    int i,t,th,h,a,phi;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>h>>th;
        if(th==0 || h==0)
            cou<<h<<"\n";
        else
        {
            phi=(int)((180*atan((float)h/a))/pie)

            if th<phi:
                cou<<(int)(ceil(h-(a/2)*tan((float)(pie*th)/180)))<<"\n";
            else:
                cout<<min(a,(int)(math.ceil(float(h**2)/(2*a*tan((pie*th)/180)))))<<"\n";
        }
    }
    return 0;
}
