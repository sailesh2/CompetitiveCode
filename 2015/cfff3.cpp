#include<stdio.h>
#include<iostream>
#include<set>
#include<iterator>

using namespace std;

int main()
{
    int i,n,x;
    cin>>n;
    set<int> st;
    for(i=0;i<n;i++)
    {
        cin>>x;
        st.insert(x);
    }
    n=st.size();
    set<int>::iterator it=st.begin();
    int arr[n];
    for(i=0;i<n;i++)
    {
        arr[i]=*it;
        it++;
    }
    if(n==1)
        cout<<"1";
    else
    {
        int a,ind[n+1],sign[n],cnt,maxi=0,lt,rt;
        if(arr[0]>arr[1])
        {
            cnt=0;
        }
        else
        {
            cnt=1;
        }
        int k=0;
        ind[k]=cnt;
        sign[k]=cnt;
        k++;
        int save=0;
        for(i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                if(cnt==1)
                {
                    if(i-save+1>maxi)
                        maxi=i-save+1;
                    cnt=0;
                    ind[k]=i;

                    sign[k]=cnt;
                    k++;
                }
            }
            else
            {
                if(cnt==0)
                {
                    save=i;
                    cnt=1;
                    ind[k]=i;

                    sign[k]=cnt;
                    k++;
                }
            }
        }
        if(cnt==1)
        {
            if(n-save>maxi)
                maxi=n-save;
        }
        ind[k]=n-1;
        ind[k+1]=n;
        sign[k]=1-cnt;
        k++;
        //for(i=0;i<k;i++)
          //  cout<<sign[i]<<" ";


        int leftz[n],lefto[n],rightz[n],righto[n];
        save=-1;
        for(i=0;i<k;i++)
        {
            leftz[i]=save;
            if(sign[i]==0)
                save=i;
        }
        save=-1;
        for(i=0;i<k;i++)
        {
            lefto[i]=save;
            if(sign[i]==1)
                save=i;
        }
        save=k;
        for(i=k-1;i>=0;i--)
        {
            rightz[i]=save;
            if(sign[i]==0)
                save=i;
        }
        save=k;
        for(i=k-1;i>=0;i--)
        {
            righto[i]=save;
            if(sign[i]==1)
                save=i;
        }


        for(i=0;i<k;i++)
        {
            a=ind[i];
            if(sign[i]==0)
            {
                if(a!=n-1)
                {
                    if(a>0)
                    {
                        if((arr[a+1]-arr[a-1])>1)
                        {
                            rt=ind[rightz[i]];
                            lt=ind[leftz[i]];
                            //cout<<rt<<" "<<lt<<"\n";
                            if((rt-lt)>maxi)
                                maxi=rt-lt;
                        }
                        else
                        {
                            rt=ind[rightz[i]];
                            lt=ind[i];
                            if((rt-lt)+1>maxi)
                                maxi=rt-lt+1;
                        }
                    }
                    else
                    {
                            rt=ind[rightz[i]];
                            if((rt+1)>maxi)
                                maxi=rt+1;
                    }
                }
            }
            else
            {
                if(a!=0)
                {
                    if(a<n-1)
                    {
                        if((arr[a+1]-arr[a-1])>1)
                        {
                            rt=ind[righto[i]];
                            lt=ind[lefto[i]];
                            if((rt-lt)>maxi)
                                maxi=rt-lt;
                        }
                        else
                        {
                            rt=ind[righto[i]];
                            lt=ind[i];
                            if((rt-lt)+1>maxi)
                                maxi=rt-lt+1;
                        }
                    }
                    else
                    {
                            lt=ind[lefto[i]];
                            if((n-lt+1)>maxi)
                                maxi=n-lt+1;
                    }
                }
            }
            //cout<<maxi<<"  ";
        }
        cout<<maxi;
    }
    return 0;
}
