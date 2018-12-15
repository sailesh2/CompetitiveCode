#include<stdio.h>
#include<conio.h>
#include<set>
#include<iterator>
#include<iostream>
#include<map>

using namespace std;
int main()
{
	set< pair<int,int> > s;
s.insert(pair<int,int>(3,40));
map<int,int> mapk;
map<int,int>::iterator it;
mapk.insert(make_pair(3,2));
int k=mapk.count(1);
it=mapk.find(900);
cout<<it->second;

/*pair<int,int> p(1,2);
mapk.insert(make_pair(p,12));
it=mapk.find(pair<int,int>(2,1));
cout<<it->second;
it=mapk.find(pair<int,int>(3,5));
cout<<it->second;
mapk.insert(make_pair(p,12));
for(it=mapk.begin();it!=mapk.end();++it)
{
	cout<<it->second;
}
/*s.insert(pair<int,int>(0,0));
	s.insert(pair<int,int>(1,10));
	s.insert(pair<int,int>(2,30));
	s.insert(pair<int,int>(7,60));
s.insert(pair<int,int>(7,60));
	s.insert(pair<int,int>(8,100));

int a=7,b=60;
	/*cout<<s.count(pair<int,int>(a,b));
cout<<s.count(pair<int,int>(7,6));
cout<<s.count(pair<int,int>(6,60));
cout<<s.count(pair<int,int>(6,7));
	/*s.insert(20);
	s.insert(30);
	s.insert(19);
	set< pair<int,int> >::iterator it=s.lower_bound(pair<int,int>(6,99));
	it--;*/
	//printf("%d",it->second);
	getch();
	return 0;
}
