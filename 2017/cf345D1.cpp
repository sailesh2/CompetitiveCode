#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,a,b,t,tf,tb,fr,bk,tf1,tb1,fr1,bk1;
    cin>>n>>a>>b>>t;
    string s;
    cin>>s;

    int v=(s[0]=='w')?b:0;
    int timeTaken=1+v;

    if(timeTaken>t){
        cout<<"0";
    } else{
        int fr=0,bk=n-1,cnt=0,ctr=1;
        while(fr<bk){
            if(cnt==0){
                v=(s[fr+1]=='w'?b:0);
                tf=a+1+v;
                v=(s[bk]=='w'?b:0);
                tb=a*(n-(bk-fr))+1+v;


                if(tf<tb){
                    fr=fr+1;
                } else if(tf>tb){
                    bk=bk-1;
                    cnt=1;
                } else{
                    fr1=fr+1;
                    bk1=bk-1;
                    while(fr1<bk1){
                        v=(s[fr1+1]=='w'?b:0);
                        tf1=a+1+v;

                        v=(s[bk1]=='w'?b:0);
                        tb1=a+1+v;

                        if(!(tf1==tb1))
                            break;
                        else{
                            fr1++;
                            bk1--;
                        }
                    }
                    if(tf1<=tb1){
                        fr=fr+1;
                    } else {
                        bk=bk-1;
                        cnt=1;
                    }
                }

            } else{
                v=(s[bk]=='w'?b:0);
                tb=a+1+v;
                v=(s[fr+1]=='w'?b:0);
                tf=a*(n-(bk-fr))+1+v;

                if(tf<tb){
                    fr=fr+1;
                    cnt=0;
                } else if(tf>tb){
                    bk=bk-1;
                } else{
                    fr1=fr+1;
                    bk1=bk-1;
                    while(fr1<bk1){
                        v=(s[fr1+1]=='w'?b:0);
                        tf1=a+1+v;

                        v=(s[bk1]=='w'?b:0);
                        tb1=a+1+v;

                        if(!(tf1==tb1))
                            break;
                        else{
                            fr1++;
                            bk1--;
                        }
                    }
                    if(tf1<tb1){
                        fr=fr+1;
                        cnt=0;
                    } else {
                        bk=bk-1;
                    }
                }
            }


            cout<<min(tf,tb)<<" "<<cnt<<" "<<timeTaken<<"\n";
            timeTaken=timeTaken+min(tf,tb);
            if(timeTaken>t)
                break;
            ctr++;

        }
        cout<<ctr;
    }
    return 0;
}
