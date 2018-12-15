#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>

using namespace std;

int ctr=0,ctr2=0;
int n;
set<string> sets;
void fun(string,char*,vector<char>,int,int,int);
int main()
{
    string s;
    cin>>s;
    n=s.length();
    char msg[11];
    vector<char> st;
    fun(s,msg,st,0,-1,-1);
    cout<<ctr2<<" "<<ctr;
    return 0;
}
void fun(string s,char *msg,vector<char> st,int top,int topst,int topmsg)
{
    if(topmsg==n-1)
    {
        int cnt=0;
        //ctr++;
        int i;
        string s1="";
        //cout<<topmsg<<" ";
        for(i=0;i<n;i++)
        {
            s1=s1+msg[i];
        }
        if(sets.count(s1)==0)
        {
            sets.insert(s1);
            ctr++;
        }
        for(i=0;i<n;i++)
        {
            if(msg[i]!=s[i])
            {
                cnt=1;
                break;
            }
        }
        if(cnt==0)
            ctr2++;
        return;
    }
    char tobepushed;
    if(topst<n-1 && top<n)
    {
        //topst++;
        tobepushed=s[top];
   // cout<<"push\n";
    //st[topst+1]=s[top];
    st.push_back(s[top]);
    //cout<<st[topst+1]<<" "<<topst+1<<"\n";

    fun(s,msg,st,top+1,topst+1,topmsg);
    st.erase(st.end()-1);
    }
    if(topst>=0)
    {
      //  cout<<"pop\n";
       // cout<<st[topst]<<"---"<<topst<<"\n";
        char val=st[topst];
        msg[topmsg+1]=st[topst];
        st.erase(st.end()-1);
        fun(s,msg,st,top,topst-1,topmsg+1);
        st.push_back(val);
    }
    return;
}
