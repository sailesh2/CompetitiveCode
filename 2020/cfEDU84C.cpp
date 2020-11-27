#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,k,x,y;
    cin>>n>>m>>k;
    int init[k][2];
    int fin[k][2];

    int d;
    int taken[k];
    string ans="";
    for(int i=0;i<k;i++){
        cin>>x>>y;
        x--;
        y--;
        taken[i]=0;
        init[i][0]=x;
        init[i][1]=y;
    }
    for(int i=0;i<k;i++){
        cin>>x>>y;
        x--;
        y--;
        fin[i][0]=x;
        fin[i][1]=y;
    }


    for(int i=0;i<k;i++){
        int save=-1;
        int mini=1000000000;
        for(int j=0;j<k;j++){
            if(taken[j]==0){
                d=abs(fin[j][0]-init[j][0]) + abs(fin[j][1]-init[j][1]);
                if(d<mini){
                    mini=d;
                    save=j;
                }
            }
        }

        taken[save]=1;
        d=abs(init[save][0]-fin[save][0]);

        if(fin[save][0]<init[save][0]){
            for(int j=0;j<d;j++){
                ans.push_back('U');
            }
            for(int j=0;j<k;j++){
                init[j][0] = max(0,init[j][0] - d);
            }
        }else if(fin[save][0]>init[save][0]){
            for(int j=0;j<d;j++){
                ans.push_back('D');
            }

            for(int j=0;j<k;j++){
                init[j][0] = min(n-1,init[j][0] + d);
            }
        }




        d=abs(init[save][1]-fin[save][1]);

        if(fin[save][1]<init[save][1]){
            for(int j=0;j<d;j++){
                ans.push_back('L');
            }
            for(int j=0;j<k;j++){
                init[j][1] = max(0,init[j][1] - d);
            }
        }else if(fin[save][1]>init[save][1]){
            for(int j=0;j<d;j++){
                ans.push_back('R');
            }

            for(int j=0;j<k;j++){
                init[j][1] = min(m-1,init[j][1] + d);
            }
        }
    }

    int len = ans.length();
    if(len>(2*n*m)){
        cout<<"-1";
    }else{
        if(len==0){
            cout<<"0";
        }else{
        cout<<len<<"\n";
        cout<<ans;
        }
    }
    return 0;
}
