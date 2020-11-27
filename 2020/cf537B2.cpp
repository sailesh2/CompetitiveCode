#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int a,n,m,k,sm=0,ctr,pos;
    cin>>n>>k>>m;
    ctr=n;
    multiset<pair<long long int,long long int> > arr;
    multiset<pair<long long int,long long int> >::iterator arrIt;
    for(long long int i=0;i<n;i++){
        cin>>a;
        sm=sm+a;
        arr.insert(make_pair(a,i));
    }
    long long int inc=k*ctr,c=0;
    while(m>0){
        arrIt = arr.begin();
        a=arrIt->first;
        pos=arrIt->second;
        if(arr.size() == 1){
            if(inc>0){
                sm++;
                arr.erase(arrIt);
                arr.insert(make_pair(a+1,pos));
                inc--;
                c++;
            }
        }
        else{
            if(inc>0){
                if((double)(sm+1)/(ctr) > (double)(sm-a)/(ctr-1)){
                    sm++;
                    arr.erase(arrIt);
                    arr.insert(make_pair(a+1,pos));
                    c++;
                }else{
                    if((double)(sm-a)/(ctr-1) > (double)(sm)/(ctr)){
                        sm=sm-a;
                        arr.erase(arrIt);
                        ctr--;
                        inc=k*ctr-c;
                    }
                }
            }else{
                if((double)(sm-a)/(ctr-1) > (double)(sm)/(ctr)){

                    sm=sm-a;
                    arr.erase(arrIt);
                    ctr--;
                    inc=k*ctr-c;
                }
            }
        }
        m--;
    }
     cout<<fixed<<setprecision(20)<<(double)sm/ctr;
    return 0;
}
