#include<stdio.h>
#include<string.h>

int main()
{
   int len,i,n;
   int j,k;
   printf("enter o. of strings\n");
   scanf("%d",&n);
   char p[n][100];
   for(i=0;i<n;i++)
   {
       scanf("%s",p[i]);
   }
   char *in[n];
   for(i=0;i<n;i++)
   {
       in[i]=(char *)p[i];
    }
   
   char en[n];
   char ch;
   char *c;
   int m,q;
   for(i=0;i<n;i++)
   {
       
       for(k=0;k<n;k++)
       {
            len=strlen(in[k]);
            j=len-i-1;
            if(j<0)
              en[k]=0;
            else
            en[k]=in[k][j];
       }
 
   
       printf("\n");
       for(m=0;m<n;m++)
       {
          for(q=m;q<n;q++)
          {
             if((int)en[m]<(int)en[q])
             {
                 ch=en[q];
                 en[q]=en[m];
                 en[m]=ch;
                
                  c=in[q];
                  in[q]=in[m];
                  in[m]=c;
             }
          }
       }
       
   }
   for(i=0;i<n;i++)
   {
       printf("%s ",in[i]);
   }
   return 0;
}
