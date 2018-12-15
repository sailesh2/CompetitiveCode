#include<stdio.h>
#include<iostream>
#include<string.h>
#include<set>

using namespace std;

int main()
{
    set<string> st;
    string s="abc";
    st.insert(s);
    string s1="abcd";
    cout<<st.count(s1);
    return 0;
}
