#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

class ThePalindrome
{
	public:
	int find(string s)
	{
		int ctr=0,cnt=0,save=1;
		int fir,last;
		fir=0;
		last=s.length()-1;
		while(fir<last)
		{
			if(s[0]!=s[last])
				cnt=1;
			if(s[fir]==s[last])
			{
				fir++;
				last--;
			}
			else
			{
				if(cnt==1)
				{
					save=1;
					ctr=ctr+fir+1;
					fir=0;
				}
				else
					save=0;
				last--;
			}
		}
		if(save==0)
			ctr=1;
		int ctr2=0;
		cnt=0;
		fir=0;
		save=1;
		last=s.length()-1;
		int len=s.length()-1;
		while(fir<last)
		{
			if(s[fir]!=s[len])
				cnt=1;
			if(s[fir]==s[last])
			{
				fir++;
				last--;
			}
			else
			{
				if(cnt==1)
				{
					save=1;
					ctr2=ctr2+len-last+1;
					last=len;
				}
				else
					save=0;
				fir++;
			}
		}
		if(save==0)
			ctr2=1;
		//cout<<ctr<<" "<<ctr2;
		if(ctr<ctr2)
		return s.length()+ctr;
		else
		return s.length()+ctr2;
	}
};
int main()
{
ThePalindrome ob;
cout<<ob.find("aaaabbbaaaaaaaaaababaabaaabbaaaaaaaaaaabaaaaaa");
return 0;
}
