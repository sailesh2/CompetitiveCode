#include<stdio.h>
#include<iostream>
#include<math.h>
#include<set>

using namespace std;

int main()
{
    int i,t,ctra,ctrb,acntr,bcntr,a,b,a1,b1,chk,save,ht;
    cin>>t;
    string str;
    int cnt=0;
    i=0;
    while(i<t)
    {
        cin>>str;
        if(str[1]=='i')
            cnt=1-cnt;
        else
        {
            set<int> st;
            cin>>a>>b;
            a1=a;
            acntr=0;
            while(a1!=0)
            {
                st.insert(a1);
                a1=a1/2;
                acntr++;
            }
            ctrb=0;
            bcntr=0;
            b1=b;
            chk=0;
            while(b1!=0)
            {
                bcntr++;
                if(chk==0)
                {
                    ctrb++;
                    if(st.count(b1)>0)
                    {
                        save=b1;
                        chk=1;
                    }
                }
                b1=b1/2;
            }
            ctra=0;
            a1=a;
            while(1)
            {
                ctra=ctra+1;
                if(a1==save)
                    break;
                a1=a1/2;
            }

            ht=((acntr-ctra))%2;
            //cout<<ctra<<" "<<ctrb<<"\n";
            //cout<<acntr<<" "<<bcntr<<"\n";
            if(cnt==0)
            {
                if(str[1]=='b')
                {
                    if((acntr-1)%2==0)
                        ctra=ctra/2+ctra%2;
                    else
                        ctra=ctra/2;
                    if((bcntr-1)%2==0)
                        ctrb=ctrb/2+ctrb%2;
                    else
                        ctrb=ctrb/2;
                }
                else
                {
                    if((acntr-1)%2==0)
                        ctra=ctra/2;
                    else
                        ctra=ctra/2+ctra%2;
                    if((bcntr-1)%2==0)
                        ctrb=ctrb/2;
                    else
                        ctrb=ctrb/2+ctrb%2;
                }
            }
            else
            {
                if(str[1]=='b')
                 {
                    if((acntr-1)%2!=0)
                        ctra=ctra/2+ctra%2;
                    else
                        ctra=ctra/2;
                    if((bcntr-1)%2!=0)
                        ctrb=ctrb/2+ctrb%2;
                    else
                        ctrb=ctrb/2;
                 }
                else
                {
                    if((acntr-1)%2!=0)
                        ctra=ctra/2;
                    else
                        ctra=ctra/2+ctra%2;
                    if((bcntr-1)%2!=0)
                        ctrb=ctrb/2;
                    else
                        ctrb=ctrb/2+ctrb%2;
                }
            }
            if( (cnt==0 && ht==0 && str[1]=='b') || (cnt==0 && ht==1 && str[1]=='r') || (cnt==1 && ht==1 && str[1]=='b') || (cnt==1 && ht==0 && str[1]=='r'))
                cout<<ctra+ctrb-1<<"\n";
            else
                cout<<ctra+ctrb<<"\n";
        }
        i=i+1;
    }
    return 0;
}




