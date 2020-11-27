#include<bits/stdc++.h>

using namespace std;
long long int n,k,l1,r1,l2,r2;

long long int intersectDist(){
    return min(r1,r2) - max(l1,l2);
}

long long int unionDist(){
    return r1-l1+1 + r2-l2+1;
}

long long int stretchDist(){
    return max(r2,r1) - min(l1,l2);
}

long long int minSteps(){
    long long int initDist = intersectDist();
    long long int totDist = unionDist();
    long long int stretch = stretchDist();
    if(initDist*n>=k)
        return 0;

    long long int remDist;
    long long int steps=0;
    if(initDist<=0){
        remDist = k;

        for(int i=0;i<n;i++){

            if(abs(initDist)<remDist){
                steps=steps+abs(initDist);
                if(remDist-stretch<=0){
                    steps = steps+remDist;
                    remDist = 0;
                    break;
                }else{
                    remDist = remDist - stretch;
                    steps = steps + stretch;
                }
            }else{
                if(i==0){
                    steps=steps+abs(initDist);


                    if(remDist-stretch<=0){
                        steps = steps+remDist;
                    }
                    else{
                        steps = steps + stretch + 2*(remDist-stretch);
                    }
                }else{
                    steps = steps + 2*remDist;
                }
                remDist=0;
                break;
            }
        }

        if(remDist>0)
            steps = steps + 2*remDist;

    }else{
       remDist = k-initDist*n;
       if((stretch*n)>=k)
            steps = steps + remDist;
       else{
           steps = steps + ((totDist-2*(initDist+1))*n);
           remDist = k - (stretch*n);
           steps = steps + 2*remDist;
       }
    }

    return steps;
}

int main(){
    long long int t;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>n>>k;
        cin>>l1>>r1>>l2>>r2;
        cout<<minSteps()<<"\n";
    }
    return 0;
}
