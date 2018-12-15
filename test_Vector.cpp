#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector
#include<conio.h>

int main () {
 int myints[] = { 10, 20, 30 ,40 };
 // int * p;

  // pointer to array element:
 // p = std::find (myints,myints+4,30);
 // ++p;
  //std::cout << "The element following 30 is " << *p << '\n';

  std::vector<int> myvector (myints,myints+4);
  std::vector<int>::iterator it;
  std::vector<std::vector<int> > v(10,std::vector<int>(2,0));
  int i,j;
  for(i=0;i<10;i++)
  {
		for(j=0;j<2;j++)
		std::cout<<v[i][j]<<"  ";
		std::cout<<"\n";
  }
  v[4][1]=5;
  for(i=0;i<10;i++)
  {
		for(j=0;j<2;j++)
		std::cout<<v[i][j]<<"  ";
		std::cout<<"\n";
  }
  
  // iterator to vector element:
  it = find (myvector.begin(), myvector.end(), 30);
  if(it==myvector.end())
  {
		std::cout<<"hello\n";
  }
  ++it;
  std::cout << "The element following 30 is " << *it << '\n';
  
  getch();


  return 0;
}
