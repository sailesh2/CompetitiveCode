#include<bits/stdc++.h>

using namespace std;

class TopXorerEasy{
public:
    int maximalRating(int a,int b,int c){
        int arr[100]={0};
        int brr[100]={0};
        int crr[100]={0};
        int i=0,ctr,lena,lenb,lenc,cnt;
        while(a>0){
            arr[i++]=a%2;
            a=a/2;
        }
        lena=i;
        i=0;
        while(b>0){
            brr[i++]=b%2;
            b=b/2;
        }
        lenb=i;
        i=0;
        cnt=0;
        while(c>0){
            crr[i++]=c%2;
            c=c/2;
        }
        lenc=i;
        int len=max(lena,max(lenb,lenc));
        i=len-1;

        vector<int> dig;
        while(i>=0){
            if(cnt==1){
                dig.push_back(1);
            }else{
                ctr=0;
                if(i<lena){
                    if(arr[i]==1)
                    ctr++;
                }

                if(i<lenb){
                    if(brr[i]==1)
                    ctr++;
                }

                if(i<lenc){
                    if(crr[i]==1)
                    ctr++;
                }

                if(ctr>1){
                    cnt=1;
                    dig.push_back(1);
                } else if(ctr==1){
                    dig.push_back(1);
                } else{
                    dig.push_back(0);
                }
            }
            i--;
        }

        int sm=0,p=1;
        for(int j=dig.size()-1;j>=0;j--){
            sm=sm+p*dig[j];
            p=p*2;
        }
        return sm;
    }
};
