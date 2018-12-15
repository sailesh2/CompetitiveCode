#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char *s;
	getline(s);
	printf("%s",s);
   // long long int len=strlen(s1);
    //printf("%lld",len);
    /*long long int i,k=0,cnt=0,arr[200]={0};
    int d[200];
    for(i=0;i<len;i++)
    {
        if(arr[(int)s[i]]==0)
        {
            d[k]=(int)s[i];
                k++;
        }
        arr[(int)s[i]]++;
    }
    for(i=0;i<len;i++)
        printf("%lld  ",arr[(int)s[i]]);
    /*for(i=0;i<k;i++)
    {
        if(arr[d[i]]%2!=0)
            cnt++;
        if(cnt>1)
        {
            printf("NO");
            break;
        }
    }
    if(cnt<=1)
    {
        printf("YES");
    }*/
    return 0;
}
