#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int x,a,b,c;
        for(int j=0;j<n;j++){
            cin>>x;
            if(j==0)
                a=x;
            else if(j==1)
                b=x;
            else if(j==n-1)
                c=x;
        }

        if((a+b)<=c){
            cout<<"1 2 "<<n<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
    return 0;
}
