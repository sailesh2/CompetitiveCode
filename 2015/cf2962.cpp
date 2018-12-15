#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>
#include<iterator>

using namespace std;

int main()
{
    int i,cnt=0,len,k=0,save=-1,save2=-1;
    cin>>len;
    string s1,s2;
    cin>>s1>>s2;
    int arr[1000]={0},brr[1000]={0};
    for(i=0;i<len;i++)
    {
        if(s1[i]!=s2[i])
            k++;
    }
    for(i=0;i<len;i++)
    {
        if(s1[i]!=s2[i])
        {
            if(arr[(int)s2[i]]!=0)
            {
                if(arr[(int)s2[i]]==brr[(int)s1[i]])
                {
                    cnt=2;
                    save=i+1;
                    save2=arr[(int)s2[i]];
                    break;
                }
                else
                {
                    save=i+1;
                    save2=arr[(int)s2[i]];
                    cnt=1;
                }
            }
            if(brr[(int)s1[i]]!=0)
            {
                if(arr[(int)s2[i]]==brr[(int)s1[i]])
                {
                    cnt=2;
                    save=i+1;
                    save2=arr[(int)s2[i]];
                    break;
                }
                else
                {
                    save=i+1;
                    save2=brr[(int)s1[i]];
                    cnt=1;
                }
            }
            arr[(int)s1[i]]=i+1;
            brr[(int)s2[i]]=i+1;
        }
    }
    map<pair<char,char>,int> mp;
    map<pair<char,char>,int>::iterator it;
    if(cnt<2)
    {
        for(i=0;i<len;i++)
        {
            if(s1[i]!=s2[i])
            {
            pair<char,char> p1=make_pair(s2[i],s1[i]);
            pair<char,char> p2=make_pair(s1[i],s2[i]);

            if(mp.find(p1)!=mp.end())
            {
                cnt=2;
                save=i+1;
                it=mp.find(p1);
                save2=it->second;
                break;
            }
            mp.insert(make_pair(p2,i+1));
            }
        }
    }
    cout<<k-cnt<<"\n";
    cout<<save2<<" "<<save;
    return 0;
}
