#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int i =0,j=s.length()-1;
    int ctr = 0;
    while(i<=j) {
        if(s[i] != s[j]){
            ctr++;
        }
        i++;
        j--;
    }
    if(ctr==1){
        cout<<"YES";
    } else {
        if(ctr == 0 && s.length()%2 != 0)
            cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}
