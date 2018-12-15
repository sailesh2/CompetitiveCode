#include<stdio.h>
#include<iostream>
#include<set>
#include<iterator>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main()
{
    long long int i,n,x,y,ctr,mini,x1,y1,x2,y2,j;
    float len,slope,m,a,b;
    set< pair<int,int> > st;
    set< pair<int,int> >::iterator it;
    cin>>n;
    int xarr[n],yarr[n];
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        xarr[i]=x;
        yarr[i]=y;
        st.insert(make_pair(x,y));
    }
    if(n<=2)
        cout<<4-n<<"\n";
    else
    {
        mini=100;
        for(i=0;i<n;i++)
        {
            x1=xarr[i];
            y1=yarr[i];
            for(j=i+1;j<n;j++)
            {
                ctr=0;
                x2=xarr[j];
                y2=yarr[j];

                len=(float)(sqrt(abs(x2-x1)*abs(x2-x1)+abs(y2-y1)*abs(y2-y1)));
                if(x1==x2)
                    slope=0;
                else if(y1==y2)
                    slope=100000000;
                else
                    slope=-1*((float)(x1-x2)/(y1-y2));
                m=slope;
                if(m==100000000)
                {
                    a=x1;
                    b=y1+len;
                }
                else
                {
                    a=x1+len*((float)1/(sqrt(1+m*m)));
                    b=y1+len*((float)m/(sqrt(1+m*m)));
                }
                if(a==floor(a) && b==floor(b))
                {
                    it=st.find(make_pair(a,b));
                    if(it!=st.end())
                        ctr++;
                }
                if(m==100000000)
                {
                    a=x2;
                    b=y2+len;
                }
                else
                {
                    a=x2+len*((float)1/(sqrt(1+m*m)));
                    b=y2+len*((float)m/(sqrt(1+m*m)));
                }
                if(a==floor(a) && b==floor(b))
                {
                    it=st.find(make_pair(a,b));
                    if(it!=st.end())
                        ctr++;
                }
                if(2-ctr<=mini)
                    mini=2-ctr;
            }
        }
        cout<<mini;
    }
    return 0;
}
