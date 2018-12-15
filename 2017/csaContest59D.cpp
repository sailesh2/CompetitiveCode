#include<bits/stdc++.h>

using namespace std;

int findFac(int check,int m,int a,int b){
    if(check==0){
        if(a==0){
            if(b==1){
                return 1;
            }else{
                return -1;
            }
        }else if(a<0){
            return 0;
        }else{
            return -1;
        }
    }
    vector<int> bin;
    int check2=check;
    while(check2>0){
        bin.push_back(check2%2);
        check2/2;
    }
    int ctr=0;
    int p[2][2]={{1,1},{1,0}};
    int p1[2][2]={{1,1},{1,0}};
    int p2[2][2]={{1,1},{1,0}};
    int ans[2][2];
    int ans2[2][2];
    int cnt=0;
    while(ctr<bin.size()){
        if(bin[ctr]==1){
            if(cnt==0)
            {
                ans[0][0]=p[0][0];
                ans[0][1]=p[0][1];
                ans[1][0]=p[1][0];
                ans[1][1]=p[1][1];
            }else{
                ans[0][0]=(ans[0][0]*p[0][0]+ans[0][1]*p[1][0])%m;
                ans[0][1]=(ans[0][0]*p[0][1]+ans[0][1]*p[1][1])%m;
                ans[1][0]=(ans[1][0]*p[0][0]+ans[1][1]*p[1][0])%m;
                ans[1][1]=(ans[1][0]*p[0][1]+ans[1][1]*p[1][1])%m;
            }
            cnt=1;
        }
        ctr++;
        p1[0][0]=p[0][0];
        p1[0][1]=p[0][1];
        p1[1][0]=p[1][0];
        p1[1][1]=p[1][1];

        p2[0][0]=p[0][0];
        p2[0][1]=p[0][1];
        p2[1][0]=p[1][0];
        p2[1][1]=p[1][1];

        p[0][0]=(p1[0][0]*p2[0][0]+p1[0][1]*p2[1][0])%m;
        p[0][1]=(p1[0][0]*p2[0][1]+p1[0][1]*p2[1][1])%m;
        p[1][0]=(p1[1][0]*p2[0][0]+p1[1][1]*p2[1][0])%m;
        p[1][1]=(p1[1][0]*p2[0][1]+p1[1][1]*p2[1][1])%m;
    }
    if(ans[1][1]==a){


        ans2[0][0]=(ans[0][0]*p1[0][0]+ans[0][1]*p1[1][0])%m;
        ans2[0][1]=(ans[0][0]*p1[0][1]+ans[0][1]*p1[1][1])%m;
        ans2[1][0]=(ans[1][0]*p1[0][0]+ans[1][1]*p1[1][0])%m;
        ans2[1][1]=(ans[1][0]*p1[0][1]+ans[1][1]*p1[1][1])%m;

        if(ans2[1][1]==b)
            return 1;
        else
            return -1;

    }else if(ans[1][1]<a){
        return 0;
    }else{
        return -1;
    }
}

int binSear(int m,int a,int b){
    int ctr=1;
    int save=-1;
    int save2=-1;
    int check,res;
    while(1){
        while(1){
            check=save+ctr;
            res=findFac(check,m,a,b);
            if(res==-1 || res==1)
                break;
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(res==-1){
            save=-1;
            break;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save;
}

int main(){
    int t,m,a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>m>>a>>b;
        cout<<binSear(m,a,b);
    }
    return 0;
}
