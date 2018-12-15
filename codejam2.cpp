#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

int main()
{
	int i,t,save,j,k;
	cin>>t;
	cin.ignore();
	for(i=0;i<t;i++)
	{
		string s;
		getline(std::cin,s);
		char ch[s.length()+1];
		ch[0]=' ';
		for(j=1;j<s.length()+1;j++)
		ch[j]=s[j-1];
		j=s.length();
		save=j;
		cout<<"Case #"<<i+1<<": ";
		while(j>=0)
		{
			if(ch[j]==' ')
			{
				k=j+1;
				while(k<=save)
				{
					cout<<ch[k];
					k++;
				}
				cout<<" ";
				save=j-1;
			}
			j--;
		}
		cout<<"\n";
	}
	return 0;
}
