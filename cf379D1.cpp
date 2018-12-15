#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<math.h>

using namespace std;

char tool[500005];
int findS(long long int f,long long int s,int i,long long int y,map<long long int,set<pair<long long int,int> > > xrr, char ch){
    map<long long int,set<pair<long long int,int> > >::iterator xit;
    set<pair<long long int,int> > stx;
    set<pair<long long int,int> >::iterator stit,stits;
    int cnt=0,d,ds;
    xit=xrr.find(f);
    if(xit!=xrr.end()){
        stx=xit->second;
        if(stx.size()==1){
            cnt=1;
        } else{
            stx.insert(make_pair(y,0));
            stit=stx.find(make_pair(y,0));
            stits=stx.find(make_pair(s,i));
            d=distance(stx.begin(),stit);
            ds=distance(stx.begin(),stits);
            if(ds<d){
                if(stit!=stx.begin() && tool[(--stit)->second]!=ch){
                    cnt=1;
                }
            }

            stit=stx.find(make_pair(y,0));
            if(ds>d){
                if(stit!=stx.end() && tool[(++stit)->second]!=ch){
                    cnt=1;
                }
            }
            stx.erase(stit);
        }
    }
    return cnt;
}

int main(){
    int n;
    char ch;
    cin>>n;
    long long int x,y,kx,ky;
    cin>>kx>>ky;
    long long int indx[n],indy[n];

    map<long long int,set<pair<long long int,int> > > xrr,yrr,srr,drr;
    map<long long int,set<pair<long long int,int> > >::iterator itx,ity,its,itd;
    set<pair<long long int,int> > stx,sty,sts,std1;

    int hv=0,diagS=0,diagD=0,cnt=0;

    for(int i=0;i<n;i++){
        cin>>ch>>x>>y;
        indx[i]=x;
        indy[i]=y;
        tool[i]=ch;
        itx=xrr.find(x);
        if(itx==xrr.end()){
            stx.clear();
        } else{
            stx=itx->second;
        }
        stx.insert(make_pair(y,i));
        xrr.insert(make_pair(x,stx));

        ity=yrr.find(y);
        if(ity==yrr.end()){
            sty.clear();
        } else{
            sty=ity->second;
        }
        sty.insert(make_pair(x,i));
        yrr.insert(make_pair(y,sty));

        its=srr.find(x+y);
        if(its==srr.end()){
            sts.clear();
        } else{
            sts=its->second;
            srr.erase(its);

        }
        sts.insert(make_pair(x,i));
        srr.insert(make_pair(x+y,sts));

        itd=drr.find(x-y);
        if(itd==drr.end()){
            std1.clear();
        } else{
            std1=itd->second;
            drr.erase(itd);
        }
        std1.insert(make_pair(x,i));
        drr.insert(make_pair(x-y,std1));

    }

    for(int i=0;i<n;i++){

        ch=tool[i];
        x=indx[i];
        y=indy[i];

        if(x==kx || y==ky){
            hv=1;
        }
        if(abs(x-kx)==abs(y-ky)){
            if(x-y==kx-ky)
                diagD=1;
            else
                diagS=1;
        }

        if(ch=='R'){
            if(hv==1){

                if(x==kx){
                    cnt=findS(x,y,i,ky,xrr,'B');
                }

                if(y==ky){
                    cnt=findS(y,x,i,kx,yrr,'B');
                }
            }
        } else if(ch=='B'){
            if(diagS==1){
                cnt=findS(x+y,x,i,kx,srr,'R');

            } else{
                cnt=findS(x-y,x,i,kx,drr,'R');

            }

        } else{
            if(hv==1 || diagS==1 || diagD==1){
                if(hv==1){
                    if(x==kx){
                        cnt=findS(x,y,i,ky,xrr,'D');
                    }
                    if(y==ky){
                        cnt=findS(y,x,i,kx,yrr,'B');
                    }
                }

                if(diagS==1){
                    cnt=findS(x+y,x,i,kx,srr,'R');
                } else{
                    cnt=findS(x-y,x,i,kx,drr,'R');
                }
            }
        }

        hv=0;
        diagS=0;
        diagD=0;
        if(cnt==1)
            break;
    }


    if(cnt==1){
        cout<<"YES";
    } else{
        cout<<"NO";
    }
    return 0;
}
