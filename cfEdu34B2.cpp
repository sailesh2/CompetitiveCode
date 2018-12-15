#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int h1,a1,c1;
    long long int h2,a2,v;

    cin>>h1>>a1>>c1;
    cin>>h2>>a2;

    int minRounds=(int)ceil((float)h2/a1);
    minRounds--;
    int minHeals=0,save=minRounds;
    while(1){
        if(h1-(minRounds*a2) <=0){
            minHeals++;
            minRounds++;
            h1=h1+c1;
        }else{
            break;
        }

    }
    cout<<minHeals+save+1<<"\n";
    for(int i=0;i<minHeals;i++){
        cout<<"HEAL\n";
    }
    for(int i=0;i<save+1;i++){
        cout<<"STRIKE\n";
    }
    return 0;
}
