#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<math.h>
#include<string>

using namespace std;
string s;
int l,glr=0,glb=0,gly=0,glg=0;


int fun(int i){
    if(i==l){
        return 0;
    }

    int e=0,no=0;

    if(s[i]=='!'){

        no=0;
        for(int j=i+1;j<=min(i+3,l-1);j++){
            if(s[j]=='R'){
                no=1;
                break;
            }
        }

        for(int j=i-1;j>=max(0,i-3);j--){
            if(s[j]=='R'){
                no=1;
                break;
            }
        }
        if(no==0){
        s[i]='R';
        e=fun(i+1);

        if(e==0){
            glr++;
            return 0;

        }
        }

        no=0;
        for(int j=i+1;j<=min(i+3,l-1);j++){
            if(s[j]=='G'){
                no=1;
                break;
            }
        }

        for(int j=i-1;j>=max(0,i-3);j--){
            if(s[j]=='G'){
                no=1;
                break;
            }
        }
        if(no==0){
        s[i]='G';
        e=fun(i+1);

        if(e==0){
            glg++;
            return 0;
        }
        }


        no=0;
        for(int j=i+1;j<=min(i+3,l-1);j++){
            if(s[j]=='B'){
                no=1;
                break;
            }
        }

        for(int j=i-1;j>=max(0,i-3);j--){
            if(s[j]=='B'){
                no=1;
                break;
            }
        }
        if(no==0){
        s[i]='B';
        e=fun(i+1);

        if(e==0){
            glb++;
            return 0;
        }
        }

        no=0;
        for(int j=i+1;j<=min(i+3,l-1);j++){
            if(s[j]=='Y'){
                no=1;
                break;
            }
        }

        for(int j=i-1;j>=max(0,i-3);j--){
            if(s[j]=='Y'){
                no=1;
                break;
            }
        }
        if(no==0){
        s[i]='Y';
        e=fun(i+1);


        if(e==0){
            gly++;
            return 0;
        }
        }
        s[i]='!';
        return 1;

    } else{

        return fun(i+1);
    }

}

int main(){
    cin>>s;
    l =s.length();
    fun(0);
    cout<<glr<<" "<<glb<<" "<<gly<<" "<<glg;
    return 0;
}
