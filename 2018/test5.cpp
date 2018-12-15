#include <stdio.h>
#include<conio.h>
int main()
{
  char arr[] = {'a','b','c'};
  char *arr1[]={arr,arr+1,arr+2};
  char (*p)[3]=arr;
  printf("%d", sizeof(p));
  getch();
  return 0;
}
