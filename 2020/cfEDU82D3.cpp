#include<bits/stdc++.h>

using namespace std;
string getDig(long long int n){
    string s="";
    while(n>0){
        s.push_back((char)(n%2+48));
        n=n/2;
    }
    return s;
}

long long int getDivs(long long int m, long long int * bin, long long int binSize){
    string digM=getDig(m);
    long long int ctr=0;
    for(long long int i=0;i<digM.length();i++){
        if(digM[i]=='1'){
            long long int j=i,req=1,cnt=0;
            while(1){
                if(bin[j]>=req){
                    break;
                }
                if(j==0){
                    cnt=1;
                    break;
                }
                req=2*(req-bin[j]);
                j--;
            }
            if(cnt==0){
                j=i;
                req=1;
                while(1){
                    if(bin[j]>=req){
                        bin[j]=bin[j]-req;
                        break;
                    }
                    req=2*(req-bin[j]);
                    bin[j]=0;
                    j--;
                }
            }else{
                j=i+1;
                long long int cnt2=0;
                while(j<binSize){
                    if(bin[j]>0){
                        bin[j]--;
                        j--;
                        ctr++;
                        while(j>i){
                            bin[j]++;
                            j--;
                            ctr++;
                        }
                        bin[j]++;
                        cnt2=1;
                        break;
                    }
                    j++;
                }
                if(cnt2==0){
                    //cout<<i<<"----\n";
                    return -1;
                }
            }
        }
    }
    return ctr;
}

long long int binC(long long int x){
    long long int ctr=0;
    while(x>0){
        x=x/2;
        ctr++;
    }

    return ctr-1;
}

int main(){
    long long int t,m,n,x;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>m>>n;
        long long int s=0;
        long long int bin[100]={0};
        long long int binSize=0;
        for(long long int j=0;j<n;j++){
            cin>>x;
            s=s+x;
            long long int binCount = binC(x);

            bin[binCount]++;
        }
        if(s<m){
            cout<<"-1\n";
        }else{
            binSize = getDig(s).length()+1;
            cout<<getDivs(m,bin,binSize)<<"\n";
        }
    }
    return 0;
}
