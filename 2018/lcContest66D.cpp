#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    string makeLargestSpecial(string S) {
        int cnt,save,save2,ctr,ctr2,k,l1,r1,l2,r2;
        string temp;
        while(1){
            cnt=0;
            for(int i=0;i<S.length();i++){
                ctr=0;
                save=-1;
                for(int j=i;j<S.length();j++){
                    if(S[j]=='1'){
                        ctr++;
                    }else{
                        ctr--;
                    }
                    if(ctr<=0){
                        save=j;
                        break;
                    }
                }
                if(ctr==0 && save!=-1){
                    ctr2=0;
                    save2=-1;
                    for(int j=save+1;j<S.length();j++){
                        if(S[j]=='1'){
                            ctr2++;
                        }else{
                            ctr2--;
                        }
                        if(ctr2<=0){
                            save2=j;
                            break;
                        }
                    }
                    if(ctr2==0 && save2!=-1 && save2-save-1>save-i){
                        cnt=1;
                        l1=i;
                        r1=save;

                        l2=save+1;
                        r2=save2;
                        temp="";
                        for(int j=l1;j<=r1;j++){
                            temp=temp+S[j];
                        }
                        k=l1;
                        while(l2<=r2){
                            S[k]=S[l2];
                            k++;
                            l2++;
                        }
                        for(int j=0;j<temp.length();j++){
                            S[k]=temp[j];
                            k++;
                        }
                    }
                }
            }
            if(cnt==0)
                break;
        }
        return S;
    }
};
