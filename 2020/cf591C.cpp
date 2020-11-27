#include<bits/stdc++.h>

using namespace std;

long long int n,x,a,y,b,k;
long long int getIndex(long long int* val, long long int*p){
    long long int s=0;
    long long int j;
    for(j=0;j<n;j++){
        if(s>=k)
        break;
        if((j+1)%a==0 && (j+1)%b==0){
            s=s+(val[j]*(x+y))/100;

        }else if((j+1)%a==0){
            s=s+(val[j]*(x))/100;

        }else if((j+1)%b==0){
            s=s+(val[j]*(y))/100;

        }
    }
    if(s>=k)
        return j+1;
    else
        return -1;
}
int main(){
    long long int q;
    cin>>q;
    for(long long int i=0;i<q;i++){
        cin>>n;
        long long int p[n];
        long long int maxiV,miniV,maxiI,miniI;
        for(long long int j=0;j<n;j++){
            cin>>p[j];
        }
        cin>>x>>a>>y>>b>>k;

        if(a>=b){
            maxiV=x;
            miniV=y;
            maxiI=a;
            miniI=b;
        }else{
            maxiV=y;
            miniV=x;
            maxiI=b;
            miniI=a;
        }
        a=miniI;
        x=miniV;
        b=maxiI;
        y=maxiV;
        sort(p,p+n);

        long long int l=n-1;
        long long int val[n];
        for(long long int j=0;j<n;j++){

            if((j+1)%a==0){
                val[j]=p[l--];
            }
            else if((j+1)%b==0){
                val[j]=p[l--];
            }
        }

        for(int j=0;j<n;j++){
            cout<<val[j]<<" ";
        }
        long long int k1=getIndex(val,p);
        long long int save=-1,temp;
        long long int val1[n];
        for(long long int j=0;j<n;j++){

            if((j+1)%b==0){
                val[j]=p[l--];
                temp=val[j];
                val[j]=val[save];
                val[save]=temp;
                save=-1;
            }
            else if((j+1)%a==0){
                val[j]=p[l--];
                if(save==-1)
                    save=j;
            }
        }

        long long int k2=getIndex(val1,p);
        if(k1==-1 && k2==-1)
            cout<<"-1\n";
        else
            cout<<min(k1,k2)<<"\n";
    }
    return 0;
}
