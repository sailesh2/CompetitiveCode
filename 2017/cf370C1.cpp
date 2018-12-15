#include<stdio.h>
#include<iostream>

using namespace std;

bool fun(int,int,int);
int main(){
    int x,y;
    cin>>y>>x;
    int a=x,b=x,c=x;
    int ctr=0,save,save2,countr=0;
    while(1){

   //     cout<<a<<" "<<b<<" "<<c<<"\n";
        if(a==y && b==y && c==y)
            break;
        if(a!=y){
            if(fun(y,b,c)){
                a=y;
            } else{
                ctr=1;
                save=a;
                save2=a;
                while(1){
                    if(!fun(save+ctr,b,c) || save+ctr>=y)
                    {
                        if(save==save2)
                            break;
                        ctr=1;
                        save=save2;
                    } else{
                        save2=save+ctr;
                        ctr=ctr*2;
                    }
                }

                a=save2;
            }
            countr++;
        }
        if(b!=y){
            if(fun(a,y,c)){
                b=y;
            } else{
                ctr=1;
                save=b;
                save2=b;
                while(1){
                    //cout<<a<<" "<<save+ctr<<" "<<c<<" ";
                    if(!fun(a,save+ctr,c) || save+ctr>=y)
                    {
                        if(save==save2)
                            break;
                        ctr=1;
                        save=save2;
                    } else{
                        save2=save+ctr;
                        ctr=ctr*2;
                    }
                }
                b=save2;
                //cout<<"b"<<b;
            }
            countr++;
        }
        if(c!=y){
            if(fun(a,b,y)){
                c=y;
            } else{
                ctr=1;
                save=c;
                save2=c;
                while(1){
                    if(!fun(a,b,save+ctr) || save+ctr>=y)
                    {
                        if(save==save2)
                            break;
                        ctr=1;
                        save=save2;
                    } else{
                        save2=save+ctr;
                        ctr=ctr*2;
                    }
                }

                c=save2;
            }
            countr++;
        }
    }

    cout<<countr;
    return 0;
}


bool fun(int a,int b,int c){

    return (a+b>c) && (b+c>a) && (c+a>b);
}
