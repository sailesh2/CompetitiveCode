#include<iostream>


using namespace std;

int main()
{
    int i,t,j,n,qu,p,q,x,a,b;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        int s[n+1],arr[n+1],save[n+1];
        for(j=1;j<=n;j++)
        {
            cin>>s[j];
            arr[j]=j;
            save[j]=0;
        }
        cin>>qu;
        for(j=0;j<qu;j++)
        {
            cin>>x;
            if(x==0)
            {
                cin>>a>>b;
                p=arr[a];
                q=arr[b];
                while(save[p]!=0)
                {
                    p=save[p];
                }
                while(save[q]!=0)
                {
                    q=save[q];
                }
                if(s[a]>s[b])
                    save[q]=p;
                else
                    save[p]=q;
            }
            else
            {
                cin>>a;
                p=arr[a];
                while(save[p]!=0)
                {
                    p=save[p];
                }
                cout<<p<<"\n";
            }
        }
    }
    return 0;
}
