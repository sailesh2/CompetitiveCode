#include<bits/stdc++.h>

using namespace std;

int main(){
    int v1,v2,v3,vm,cnt=0;
    int savei,savej,savek;
    cin>>v1>>v2>>v3>>vm;
    for(int i=0;i<=201;i++){
        for(int j=0;j<=201;j++){
            for(int k=0;k<=01;k++){
                if(v1<=i && 2*v1>=i){
                    if(v2<=j && 2*v2>=j){
                        if(v3<=k && 2*v3>=k){
                            if(vm<=i && vm<=j && vm<=k && 2*vm>=k && 2*vm<i && 2*vm<j){
                                if(i>j && j>k){
                                    cnt=1;
                                    savei=i;
                                    savej=j;
                                    savek=k;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            if(cnt==1)
                break;
        }
        if(cnt==1)
            break;
    }
    if(cnt==0){
        cout<<"-1";
    }else{
        cout<<savei<<"\n"<<savej<<"\n"<<savek;
    }
    return 0;
}
