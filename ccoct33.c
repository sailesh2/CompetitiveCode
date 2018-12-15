#include<stdio.h>


int main()
{
    int i,t,j,n,m,save,maxi;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d",&n,&m);
        int p;
        //int arr[m];
        //int has[100001]={0};
        //char x;
        //long long int p=1;
        //maxi=0;
        printf("%d%d",n,m);
        for(j=0;j<m;j++)
        {
            scanf("%d",p);
            printf("ds");

 //           if(arr[j]>=maxi)
//                maxi=arr[j];
            printf("ds");

            //has[arr[j]-1]=2;
        }
        /*save=-1;
        for(j=0;j<maxi;j++)
        {
            if(has[j]>0)
            {
                if(save==-1)
                    save=j;
                else
                {
                    if(has[j]!=has[save])
                        p=((p%1000000009)*(j-save)%1000000009)%1000000009;
                    save=j;
                }
            }
        }
        printf("%d\n",p);*/
    }
    return 0;
}
