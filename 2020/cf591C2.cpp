#include<bits/stdc++.h>

using namespace std;

long long int n,x,a,y,b,k;

bool calSum(long long int* p, long long int m,long long int a1, long long int b1,  long long int c1){
    long long int l=n-1;
    long long int val[m];
    for(long long int j=0;j<m;j++)
        val[j]=-1;
    for(long long int j=0;j<m;j++){

        if((j+1)%a1==0 && val[j]==-1){
            val[j]=p[l--];
        }
    }
    for(long long int j=0;j<m;j++){

        if((j+1)%b1==0 && val[j]==-1){
            val[j]=p[l--];
        }
    }
    for(long long int j=0;j<m;j++){

        if((j+1)%c1==0 && val[j]==-1){
            val[j]=p[l--];
        }
    }
    long long int s=0;
    for(long long int j=0;j<m;j++){
        if(s>=k)
        break;
        if((j+1)%a==0 && (j+1)%b==0){
            s=s+(val[j]*(x+y))/100;

        }
        else if((j+1)%a==0){
            s=s+(val[j]*(x))/100;

        }
        else if((j+1)%b==0){

            s=s+(val[j]*(y))/100;

        }
    }
    return s>=k;
}
bool isPossible(long long int index, long long int* p){
    long long int c=a*b;
    //if( (x*((index+1)/a)) >= (y*(index+1)/b) ){
        return calSum(p,index+1,a,b,c)

    //}{
         || calSum(p,index+1,b,a,c)
         || calSum(p,index+1,c,a,b)
         ||calSum(p,index+1,c,b,a)
         ||calSum(p,index+1,a,c,b)
         ||calSum(p,index+1,b,c,a);
    //}
}
long long int minTickets(long long int*p){
    long long int ctr=1;
    long long int save=-1;
    long long int save2=-1;

    while(1){
        while(save+ctr<n && !isPossible(save+ctr,p)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    if(save==n-1)
        return -2;
    return save+1;
}

int main(){
    long long int q;
    cin>>q;
    for(long long int i=0;i<q;i++){
        cin>>n;
        long long int p[n];
        for(long long int j=0;j<n;j++){
            cin>>p[j];
        }
        cin>>x>>a>>y>>b>>k;
        sort(p,p+n);
        cout<<1+minTickets(p)<<"\n";
    }
    return 0;
}
