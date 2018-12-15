#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;

 int main()
 {
		char a[1000],b[1000];
		cin>>a>>b;
		int i,min=0,l=0,k=0;
		int crra[200]={0},crrb[200]={0};
		char da[1000],db[1000];
		for(i=0;i<strlen(a);i++)
		{
			if(crra[(int)a[i]]==0)
			da[k++]=a[i];
			crra[(int)a[i]]++;
		}
		for(i=0;i<strlen(b);i++)
		{
			if(crrb[(int)b[i]]==0)
			db[l++]=b[i];
			crrb[(int)b[i]]++;
		}
		for(i=0;i<k;i++)
		{
			if(crra[da[i]]>=crrb[da[i]])
			min=min+crra[da[i]]-crrb[da[i]];
		}
		for(i=0;i<l;i++)
		{
			if(crrb[db[i]]>=crra[db[i]])
			min=min+crrb[db[i]]-crra[db[i]];
		}
		cout<<min;
		return 0;
 }
