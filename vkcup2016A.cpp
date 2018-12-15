#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,c;
    cin>>n>>c;
    int p[n];
    int t[n];
    long long int nimak=0,red=0;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }

    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    long long int st=0;
    for(int i=0;i<n;i++){
        st=st+t[i];
        nimak=nimak+max((long long int)0,p[i]-st*c);
    }
    st=0;
    for(int i=n-1;i>=0;i--){
        st=st+t[i];
        red=red+max((long long int)0,p[i]-st*c);
    }
    if(nimak>red){
        cout<<"Limak";
    } else if(nimak==red){
        cout<<"Tie";
    } else{
        cout<<"Radewoosh";
    }
    return 0;
}
