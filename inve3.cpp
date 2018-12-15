#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int i,n,j,max,save;
	cin>>n;
	string s;
	cin>>s;
	i=0;
	j=0;
	char arr[10000];
	int crr[10000]={0};
	while(1)
	{
		max=0;
		while(i<n)
		{
			if(crr[int(s[i])]==0)
			{
			if(int(s[i])>max)
			{
				max=int(s[i]);
				save=i;
			}
			}
			i++;
		}
		if(max==0)
		break;
		arr[j++]=s[save];
		crr[int(s[save])]=1;
		i=save+1;
	}
	for(i=0;i<j;i++)
	cout<<arr[i];
	getch();
	return 0;
}
