#include<stdio.h>
#include<iostream>

using namespace std;

struct tree
{
    int bit;
    struct tree *left;
    struct tree *right;
};
int main()
{
    int i,t,j,n;
    cin>>t;
    for(i=0;i<t;i++)
    {
        struct tree *root,*p,*q;
        root=(struct tree *)malloc(sizeof(struct tree));
        root->bit=0;
        root->left=NULL;
        root->right=NULL;
        cin>>n;
        int arr[n],subxor[n+1];
        subxor[0]=0;
        for(j=0;j<n;j++)
        {
            cin>>arr[j];
            subxor[j+1]=subxor[j]^arr[j];
        }
        cin>>q;
        for(j=0;j<q;j++)
        {
            cin>>l>>r;
            for(k=1;k<n+1;k++)
            {
                el=arr[k];
                while(el>0)
                {
                    p=(struct tree *)malloc(sizeof(struct tree));
                    p->bit=el%2;
                    p->left=NULL;
                    p->right=NULL;

                    q=root;
                    while(1)
                    {
                        if()
                    }
                }
            }
        }
    }
    return 0;
}
