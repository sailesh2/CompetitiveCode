#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int i,j;
    char c1,c2;
    int rep[300]={0};
    for(i=0;i<m;i++)
    {
        vector<int> has,has2;
        cin>>c1>>c2;
        for(j=(int)'a';j<=(int)'z';j++)
        {
            if(rep[j]==(int)c1)
                has.push_back(j);

            if(rep[j]==(int)c2)
                has2.push_back(j);
        }
        for(j=0;j<has.size();j++)
        {
      //      cout<<j<<" "<<(char)has[j]<<" ";
            rep[has[j]]=(int)c2;
        }
        //cout<<"\n";
        for(j=0;j<has2.size();j++)
        {
          //  cout<<j<<" "<<(char)has2[j]<<" ";
            rep[has2[j]]=(int)c1;
        }


        if(rep[(int)c1]==0)
        rep[(int)c1]=c2;
        if(rep[(int)c2]==0)
        rep[(int)c2]=c1;
    }
    for(i=0;i<n;i++)
    {
        if(rep[(int)s[i]]>0)
        {
            s[i]=(char)rep[(int)s[i]];
        }
    }
    cout<<s;
    return 0;
}
