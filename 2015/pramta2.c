#include<stdio.h>

int main()
{
    int i,j,n,q;
    scanf("%d",&n);

    scanf("%d",&q);

    int arro[n],arre[n],brro[n],brre[n],ako=0,ake=0,bko=0,bke=0,idx,val,a,l,r;
    long long int sum,sum2,sum3;
    for(i=0;i<n;i++)
    {
        if(i%2!=0)
        {
            scanf("%d",&arro[ako]);
            ako++;
        }
        else
        {
            scanf("%d",&arre[ake]);
            ake++;
        }
    }

    for(i=0;i<n;i++)
    {
        if(i%2!=0)
        {
            scanf("%d",&brro[bko]);
            bko++;
        }
        else
        {
            scanf("%d",&brre[bke]);
            bke++;
        }
    }
    long long int sum_arro[100001]={0},sum_arre[100001]={0},sum_brro[100001]={0},sum_brre[100001]={0};
    for(i=1;i<=ako;i++)
    {
        idx=i;
        val=arro[i-1];
        while (idx <=ako)
        {
            sum_arro[idx-1] = (sum_arro[idx-1] + val);
            idx += (idx & -idx);
        }
    }
    for(i=1;i<=ake;i++)
    {
        idx=i;
        val=arre[i-1];
        while (idx <=ake)
        {
            sum_arre[idx-1] = (sum_arre[idx-1] + val);
            idx += (idx & -idx);
        }
    }
    for(i=1;i<=bko;i++)
    {
        idx=i;
        val=brro[i-1];
        while (idx <=bko)
        {
            sum_brro[idx-1] = (sum_brro[idx-1] + val);
            idx += (idx & -idx);
        }
    }
    for(i=1;i<=bke;i++)
    {
        idx=i;
        val=brre[i-1];
        while (idx <=bke)
        {
            sum_brre[idx-1] = (sum_brre[idx-1] + val);
            idx += (idx & -idx);
        }
    }

    for(i=0;i<q;i++)
    {
        scanf("%d%d%d",&a,&l,&r);

        l--;
        r--;
        if(a==1)
        {
            if(l%2!=0)
            {
                idx=l/2-1;
                sum = 0;
                idx++;
                while (idx > 0)
                {
                    sum = (sum + sum_arro[idx-1]);
                    idx -= (idx & -idx);
                }
                if(r%2==0)
                    idx=r-1;
                else
                    idx=r;
                idx=r/2;
                idx++;
                sum2=0;
                while (idx > 0)
                {
                    sum2 = (sum2 + sum_arro[idx-1]);
                    idx -= (idx & -idx);
                }
                sum2=sum2-sum;


                idx=(l+1)/2-1;
                idx++;
                sum = 0;
                while (idx > 0)
                {
                    sum = (sum + sum_brre[idx-1]);
                    idx -= (idx & -idx);
                }
                if(r%2!=0)
                    idx=r-1;
                else
                    idx=r;
                idx=r/2;
                idx++;
                sum3=0;
                while (idx > 0)
                {
                    sum3 = (sum3 + sum_brre[idx-1]);
                    idx -= (idx & -idx);
                }
                sum3=sum3-sum;
                printf("%lld\n",sum3+sum2);
            }
            else
            {
                idx=l/2-1;
                idx++;
                sum = 0;
                while (idx > 0)
                {
                    sum = (sum + sum_arre[idx-1]);
                    idx -= (idx & -idx);
                }
                if(r%2!=0)
                    idx=r-1;
                else
                    idx=r;
                idx=r/2;
                idx++;
                sum2=0;
                while (idx > 0)
                {
                    sum2 = (sum2 + sum_arre[idx-1]);
                    idx -= (idx & -idx);
                }
                sum2=sum2-sum;



                idx=(l+1)/2-1;
                idx++;
                sum = 0;
                while (idx > 0)
                {
                    sum = (sum + sum_brro[idx-1]);
                    idx -= (idx & -idx);
                }
                if(r%2==0)
                    idx=r-1;
                else
                    idx=r;
                idx=r/2;
                idx++;
                sum3=0;
                while (idx > 0)
                {
                    sum3 = (sum3 + sum_brro[idx-1]);
                    idx -= (idx & -idx);
                }
                sum3=sum3-sum;

                printf("%lld\n",sum3+sum2);
            }
        }
        else
        {
            if(l%2!=0)
            {
                idx=l/2-1;
                sum = 0;
                idx++;
                while (idx > 0)
                {
                    sum = (sum + sum_brro[idx-1]);
                    idx -= (idx & -idx);
                }
                if(r%2==0)
                    idx=r-1;
                else
                    idx=r;
                idx=r/2;
                idx++;
                sum2=0;
                while (idx > 0)
                {
                    sum2 = (sum2 + sum_brro[idx-1]);
                    idx -= (idx & -idx);
                }
                sum2=sum2-sum;


                idx=(l+1)/2-1;
                idx++;
                sum = 0;
                while (idx > 0)
                {
                    sum = (sum + sum_arre[idx-1]);
                    idx -= (idx & -idx);
                }
                if(r%2!=0)
                    idx=r-1;
                else
                    idx=r;
                idx=r/2;
                idx++;
                sum3=0;
                while (idx > 0)
                {
                    sum3 = (sum3 + sum_arre[idx-1]);
                    idx -= (idx & -idx);
                }
                sum3=sum3-sum;
                printf("%lld\n",sum3+sum2);
            }
            else
            {
                idx=l/2-1;
                idx++;
                sum = 0;
                while (idx > 0)
                {
                    sum = (sum + sum_brre[idx-1]);
                    idx -= (idx & -idx);
                }
                if(r%2!=0)
                    idx=r-1;
                else
                    idx=r;
                idx=r/2;
                idx++;
                sum2=0;
                while (idx > 0)
                {
                    sum2 = (sum2 + sum_brre[idx-1]);
                    idx -= (idx & -idx);
                }
                sum2=sum2-sum;



                idx=(l+1)/2-1;
                idx++;
                sum = 0;
                while (idx > 0)
                {
                    sum = (sum + sum_arro[idx-1]);
                    idx -= (idx & -idx);
                }
                if(r%2==0)
                    idx=r-1;
                else
                    idx=r;
                idx=r/2;
                idx++;
                sum3=0;
                while (idx > 0)
                {
                    sum3 = (sum3 + sum_arro[idx-1]);
                    idx -= (idx & -idx);
                }
                sum3=sum3-sum;

                printf("%lld\n",sum3+sum2);
            }
        }
    }
    return 0;
}
