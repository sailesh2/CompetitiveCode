#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,a,b,c;
    cin>>t;
    int l,u,lv,uv,l2,u2,lv2,uv2,a2,b2,c2,del;
    int savea,saveb,savec;
    int mini=1000000000;

    for(int i=0;i<t;i++){
        cin>>a>>b>>c;
        mini=1000000000;
        for(int j=1;j<=b;j++){
            l=b/j;
            u=l+1;
            lv=l*j;
            uv=u*j;

            if(j<=lv){
                a2=j;
                b2=lv;
                l2=c/b2;
                u2=l2+1;
                lv2=l2*b2;
                uv2=u2*b2;
                if(b2<=lv2){
                    c2=lv2;
                    del=abs(c2-c)+abs(b2-b)+abs(a2-a);
                    if(del<mini){
                        mini=del;
                        savea=a2;
                        saveb=b2;
                        savec=c2;
                    }
                }
                c2=uv2;
                del=abs(c2-c)+abs(b2-b)+abs(a2-a);
                if(del<mini){
                        mini=del;
                        savea=a2;
                        saveb=b2;
                        savec=c2;
                    }
            }

            a2=j;
            b2=uv;
            l2=c/b2;
            u2=l2+1;
            lv2=l2*b2;
            uv2=u2*b2;
            if(b2<=lv2){
                c2=lv2;
                del=abs(c2-c)+abs(b2-b)+abs(a2-a);
                if(del<mini){
                        mini=del;
                        savea=a2;
                        saveb=b2;
                        savec=c2;
                    }
            }
            c2=uv2;
            del=abs(c2-c)+abs(b2-b)+abs(a2-a);
            if(del<mini){
                        mini=del;
                        savea=a2;
                        saveb=b2;
                        savec=c2;
                    }
        }
        cout<<mini<<"\n";
        cout<<savea<<" "<<saveb<<" "<<savec<<"\n";
    }
    return 0;
}
