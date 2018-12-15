#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,t,j,n,k,ctr,textlen,startslen,endslen;
    cin>>t;
    char starts[1001],ends[1001],text[1001];
    int cnt,cnt2,save;
    for(i=0;i<t;i++)
    {
        ctr=0;
        int store_st[10001];
        int store_en[10001];
        scanf("%s",starts);
        scanf("%s",ends);
        scanf("%s",text);
        startslen=0;
        endslen=0;
        textlen=0;
        for(j=0;text[j]!='\0';j++)
            textlen++;
        for(j=0;starts[j]!='\0';j++)
            startslen++;
        for(j=0;ends[j]!='\0';j++)
            endslen++;
        for(j=0;j<textlen;j++)
        {
            cnt=0;
            for(k=0;k<startslen;k++)
            {
                if(j+k>=textlen)
                {
                    cnt=1;
                    break;
                }
                if(text[j+k]!=starts[k])
                {
                    cnt=1;
                    break;
                }
            }
            if(cnt==0)
            {
                save=j;
                j=j+startslen;
                for(;j<textlen;j++)
                {
                    cnt2=0;
                    for(k=0;k<endslen;k++)
                    {
                        if(j+k>=textlen)
                        {
                            cnt2=1;
                            break;
                        }
                        if(text[j+k]!=ends[k])
                        {
                            cnt2=1;
                            break;
                        }
                    }
                    if(cnt2==0)
                    {
                        j=j+endslen-1;
                        store_st[ctr]=save;
                        store_en[ctr]=j;
                        ctr++;
                        break;
                    }
                }
            }
        }
        k=0;
        for(j=0;j<textlen;j++)
        {
            if(k<ctr && j==store_st[k])
            {
                j=store_en[k];
                k++;
            }
            else
                cout<<text[j];
        }
        cout<<"\n";
    }
    return 0;
}
