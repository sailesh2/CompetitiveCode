#include<bits/stdc++.h>

using namespace std;

int main(){
    int g1,p1,g2,p2;
    cin>>g1>>p1>>g2>>p2;
    int first=(int)ceil(g1*((double)p1/100));
    int first1=first;
    if(p1>0)
        first1=(int)ceil(g1*((double)(p1-1)/100));
    int savef=first;

    int v;
    v=(int)floor(((double)savef/g1)*100);
    if(v==p1){

        for(int i=first;i>=first1;i--){
            v=(int)floor(((double)i/g1)*100);
            if(v!=p1){
                break;
            }else{
                savef=i;
            }
        }
    }else{
        savef=1000000000;
    }

    int first2=(int)floor(g1*((double)p1/100));
    int first3=first2;
    if(p1>0)
        first3=(int)floor(g1*((double)(p1-1)/100));
    int save2f=first2;

    v=(int)floor(((double)save2f/g1)*100);
    if(v==p1){
        for(int i=first2;i>=first3;i--){
            v=(int)floor(((double)i/g1)*100);
            if(v!=p1){
                break;
            }else{
                save2f=i;
            }
        }
    }else{
        save2f=1000000000;
    }
    int saveFirst=min(savef,save2f);

    int last=(int)ceil(g2*((double)p2/100));
    int last1=(int)ceil(g2*((double)(p2+1)/100));
    int savel=-1;
    for(int i=last;i<=last1;i++){
        v=(int)floor(((double)i/g2)*100);
        if(v!=p2){
            break;
        }else{
            savel=i;
        }
    }

    int last2=(int)floor(g2*((double)p2/100));
    int last3=(int)floor(g2*((double)(p2+1)/100));
    int save2l=-1;
    for(int i=last2;i<=last3;i++){
        v=(int)floor(((double)i/g2)*100);
        if(v!=p2){
            break;
        }else{
            save2l=i;
        }
    }
    int saveLast=max(savel,save2l);
    cout<<saveLast-saveFirst;
    return 0;
}
