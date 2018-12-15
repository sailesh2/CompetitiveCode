#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    string s1,s2;
    int i,t,hr1,hr2,min1,min2,sec1,sec2,sm;
    cin>>t;
    for(i=0;i<t;i++)
    {
        sm=0;
        cin>>s1>>s2;
        hr1=((int)s1[0]-48)*10+(int)s1[1]-48;
        min1=((int)s1[3]-48)*10+(int)s1[4]-48;
        sec1=((int)s1[6]-48)*10+(int)s1[7]-48;

        hr2=((int)s2[0]-48)*10+(int)s2[1]-48;
        min2=((int)s2[3]-48)*10+(int)s2[4]-48;
        sec2=((int)s2[6]-48)*10+(int)s2[7]-48;

        if(hr1<hr2)
        {
            //sm=sm+(hr2-hr1-1)*6;
            if(hr1>=0 && hr1<=5)
            {
                if(hr2<=5)
                    sm=sm+(hr2-hr1-1)*6;
                else if(hr2>=6 && hr2<=9)
                    sm=sm+(6-hr1-1)*6;
                else if(hr2>=10 && hr2<=15)
                {
                    sm=sm+(6-hr1-1)*6+(hr2-9-1)*6;
                }
                else if(hr2>=16 && hr2<=19)
                {
                    sm=sm+(6-hr1-1)*6+(16-9-1)*6;
                }
                else
                {
                    sm=sm+(6-hr1-1)*6+(16-9-1)*6+(hr2-19-1)*6;
                }
            }
            else if(hr1>=6 && hr1<=9)
            {
                if(hr2>=10 && hr2<=15)
                {
                    sm=sm+(hr2-9-1)*6;
                }
                else if(hr2>=16 && hr2<=19)
                {
                    sm=sm+(16-9-1)*6;
                }
                else if(hr2>=20)
                {
                    sm=sm+(16-9-1)*6+(hr2-19-1)*6;
                }
            }
            else if(hr1>=10 && hr1<=15)
            {
                if(hr2>=10 && hr2<=15)
                {
                    sm=sm+(hr2-hr1-1)*6;
                }
                else if(hr2>=16 && hr2<=19)
                {
                    sm=sm+(16-hr1-1)*6;
                }
                else if(hr2>=20)
                {
                    sm=sm+(16-hr1-1)*6+(hr2-19-1)*6;
                }
            }
            else if(hr1>=16 && hr1<=19)
            {
                if(hr2>=20)
                {
                    sm=sm+(hr2-19-1)*6;
                }
            }
            else
            {
                if(hr2>=20)
                    sm=sm+(hr2-hr1-1)*6;
            }
            if((hr1>=0 && hr1<=5) || (hr1>=10 && hr1<=15) ||(hr1>=20))
            {
                sm=sm+5-min1/10;
                if(s1[3]==s1[4])
                    sm++;
            }
            if((hr2>=0 && hr2<=5) || (hr2>=10 && hr2<=15) ||(hr2>=20))
            {
                sm=sm+(min2/10);
                if(min2>((min2/10)*10+(min2/10)))
                    sm++;
                else if(min2==((min2/10)*10+(min2/10)))
                {
                    if(((hr2%10)*10+(hr2/10))<=sec2)
                        sm++;
                }
            }
        }
        else
        {
            if((hr2>=0 && hr2<=5) || (hr2>=10 && hr2<=15) ||(hr2>=20))
            {
                if((min1/10)<(min2/10))
                {
                    sm=sm+(min2/10)-(min1/10)-1;
                    if(min1<=((min1/10)*10+min1/10))
                        sm++;
                    if(min2>((min2/10)*10+(min2/10)))
                        sm++;
                    else if(min2==((min2/10)*10+(min2/10)))
                    {
                        if(((hr2%10)*10+(hr2/10))<=sec2)
                            sm++;
                    }
                }
                else
                {
                    if(((min1/10)>=(min1%10)) && ((min1/10)<=(min2%10)))
                    {
                        if(((hr2%10)*10+(hr2/10))<=sec2 && ((hr2%10)*10+(hr2/10))>=sec1)
                            sm++;
                    }
                }
            }
        }
        cout<<sm<<"\n";
    }
    return 0;
}
