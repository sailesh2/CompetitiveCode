#include<bits/stdc++.h>

using namespace std;

class OrAndSumEasy{
public:
    string isPossible(long long int o,long long int s){
        int cnt=0;
        int orr[100]={0};
        int ctro=0;
        while(o>0){
            orr[ctro++]=o%2;
            o=o/2;
        }

        int srr[100]={0};
        int ctrs=0;
        while(s>0){
            srr[ctrs++]=s%2;
            s=s/2;
        }

        for(int i=0;i<max(ctro,ctrs);i++){
            if(orr[i]==0 && srr[i]==1){
                if(i-1>=0 && orr[i-1]==1 && srr[i-1]==0){
                    cnt=0;
                }else{
                    cnt=1;
                    break;
                }
            }
            else if(orr[i]==1 && srr[i]==0){
                if(i-1>=0 && orr[i-1]==1 && srr[i-1]==0){
                    cnt=1;
                    break;
                }
            }
            else if(orr[i]==0 && srr[i]==0){
                if(i-1>=0 && orr[i-1]==1 && srr[i-1]==0){
                    cnt=1;
                    break;
                }
            }else if(orr[i]==1 && srr[i]==1){
                if(i-1>=0 && orr[i-1]==1 && srr[i-1]==0){
                    srr[i]=0;
                }
            }
        }
        if(cnt==0){
            if(srr[max(ctrs,ctro)-1]==0 && orr[max(ctrs,ctro)-1]==1)
                return "Impossible";
            else
                return "Possible";
        }else{
            return "Impossible";
        }
    }
};
