#include<stdio.h>
#include<conio.h>
#include<string.h>
int strcmpare(char a[],char b[],int l);
struct table
{
       char in[10],op[5],fmt[2];
       int len;
};
int main()
{
      struct table mot[2] ;
	  char ch,word[10];
	  int k=0,i,l;
      FILE *fp;
	  for(i=0;i<2;i++)
	  {
	  printf("enter the values of table:\n");
	  scanf("%s",mot[i].in);
	  scanf("%s",mot[i].op);
	  scanf("%d",&mot[i].len);
	  scanf("%s",mot[i].fmt);
      }
      
       for(i=0;i<2;i++)
	   {
                       printf("%s\t%s\t%d\t%s\n",mot[i].in,mot[i].op,mot[i].len,mot[i].fmt);
       }
       //file read
   fp = fopen("motinstr.txt","r"); // read mode
   if( fp == NULL )
   {
      printf("Error while opening the file.\n");
      getch();
      return 0;
   }
   //print file content
   int flag=1;
   printf("MOT instruction are:\n");
   while(( ch = fgetc(fp))!= -1)
   {
		  if(ch!=' '||ch!='\n')
		  {
                   word[k]=ch;
                   k++;
          }
          if(ch==' '||ch=='\n')
          {
                   word[k]='\0';
                   l=k;
                   k=0;
          
          for(i=0;i<2;i++)
          {
                          flag=strcmpare(mot[i].in,word,l-1);
                          if(flag==0)
                          {
                          printf("%s\t%s\t%d\t%s\n",mot[i].in,mot[i].op,mot[i].len,mot[i].fmt);
                          }
          }              
    }
}
           fclose(fp);
   getch();
   return 0;
}
int strcmpare(char a[],char b[],int l)
{
    int i,ctr=0;
    for(i=0;i<l;i++)
    {
                    if(a[i]==b[i])
                    {
                                  ctr=ctr+1;
                    }
    }
    if(ctr==l)
              return 0;
    else 
              return 1;
              
}
