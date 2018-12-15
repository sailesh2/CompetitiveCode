#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    char s1[500001];
    char s2[500001];
    int i,j,t,cnt;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s",s1);
        scanf("%s,",s2);
        int arr[300]={0};
        for(j=0;s1[j]!='\0';j++)
        {
            arr[(int)s1[j]]=1;
        }
        cnt=0;
        for(j=0;s2[j]!='\0';j++)
        {
            if(arr[(int)s2[j]]==1)
            {
                cnt=1;
                break;
            }
        }
        if(cnt==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

