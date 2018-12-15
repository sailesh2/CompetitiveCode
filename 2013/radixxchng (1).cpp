#include<iostream>
#include<stdlib.h>
using namespace std;
  int bits(int n,int bit)
   {int val,i=0;
	while(i<bit)
    {val=n%2;
	 n=n/2;
	i++;
     }
     if(val==1)
     return 1;
     else return 0;
    }
void radixchng(int *a,int l,int r,int bit)
  {
   int i,j,t;
  if(bit>=0 && r>l)
  {
   int i=l;
   int j=r;
   do
    {
	 while((bits(a[i],bit)==0) && (i<j))
	 i++;
	 while((bits(a[j],bit)!=0) && (i<j))
	 j--;
	 t=a[i];
	 a[i]=a[j];
	 a[j]=t;
    }while(j!=i);
   if(bits(a[r],bit)==0)
   j=j+1;
   radixchng(a,l,j-1,bit-1);
   radixchng(a,j,r,bit-1);
 }
 else return;
   }

  int main()
  {int a[5]={2,3,1,5,4};
   radixchng(a,0,4,4);
   cout<<"array after radix exchange sort"<<endl;
   for(int i=0;i<5;i++)
   cout<<a[i]<<endl;
   system("PAUSE");
   return 0;
  }
  
