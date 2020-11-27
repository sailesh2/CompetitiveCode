#include<bits/stdc++.h>

using namespace std;
vector<int> divDP[100004];

vector<int> getDiv(int num){
    vector<int> d;
    for(int i=1;i*i<=num;i++){
        if(num%i==0){
            d.push_back(i);
            if(num/i!=i)
                d.push_back(num/i);
        }
    }
    return d;
}

void setup(){
    for(int i=1;i<=100000;i++){
        divDP[i]=getDiv(i);
    }
}

int main(){
    int t,a,b,c;
    cin>>t;
    int l,u,lv,uv,l2,u2,lv2,uv2,a2,b2,c2,del;
    int savea,saveb,savec;
    int mini=1000000000;

    setup();

    for(int i=0;i<t;i++){
        cin>>a>>b>>c;
        mini=1000000000;
        for(int j=1;j<=100000;j++){
            b2=j;
            vector<int> divs = divDP[j];
            for(int k=0;k<divs.size();k++){
                a2=divs[k];

                l=c/b2;
                u=l+1;
                lv=l*b2;
                uv=u*b2;

                if(b2<=lv){
                    c2=lv;
                    del=abs(c2-c)+abs(b2-b)+abs(a2-a);
                    if(del<mini){
                        mini=del;
                        savea=a2;
                        saveb=b2;
                        savec=c2;
                    }
                }
                c2=uv;
                del=abs(c2-c)+abs(b2-b)+abs(a2-a);
                if(del<mini){
                    mini=del;
                    savea=a2;
                    saveb=b2;
                    savec=c2;
                }
            }
        }
        cout<<mini<<"\n";
        cout<<savea<<" "<<saveb<<" "<<savec<<"\n";
    }
    return 0;
}
