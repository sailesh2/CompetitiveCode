#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>

using namespace std;

int main(){
    int n,a,b;
    char c;
    cin>>n;
    int male[370]={0};
    int female[370]={0};


    for(int i=0;i<n;i++){
        cin>>c>>a>>b;
        if(c=='M'){
            for(int j=a;j<=b;j++){
                male[j]++;
            }
        } else{
            for(int j=a;j<=b;j++){
                female[j]++;
            }
        }
    }

    int maxi=0;
    for(int i=0;i<370;i++){
        maxi=max(maxi,min(male[i],female[i]));
    }
    cout<<maxi*2;
    return 0;
}
