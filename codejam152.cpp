#include<stdio.h>
#include<iostream>
#include<set>
#include<iterator>

using namespace std;

int main()
{
    int i,t,j,d,x,save,val,ctr,mini;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>d;
        multiset<int> p;
        multiset<int>::iterator it;
        for(j=0;j<d;j++)
        {
            cin>>x;
            p.insert(x);
        }
        ctr=0;
        it=p.end();
        it--;
        save=*it;
        mini=save;
        if(mini>1)
        {
            while(1)
            {
                if((ctr+save)<mini)
                    mini=ctr+save;
                it=p.end();
                it--;
                if(*it<=1)
                {
                    break;
                }
                else
                {
                    val=*it;
                    p.erase(it);
                    if(val%2==0)
                    {
                        val=val/2;
                        p.insert(val);
                        p.insert(val);
                    }
                    else
                    {
                        val=val/2;
                        p.insert(val+1);
                        p.insert(val);
                    }
                    ctr++;
                    it=p.end();
                    it--;
                    save=*it;
                }
            }
        }
        cout<<"Case #"<<i+1<<": "<<mini<<"\n";
    }
    return 0;
}
