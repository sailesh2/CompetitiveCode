#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int h1,a1,c1;
    long long int h2,a2,v;

    cin>>h1>>a1>>c1;
    cin>>h2>>a2;

    int minRounds=(int)ceil((float)h2/a1);
    minRounds--;
    int minHeals=0,minHealsTot=0,save=minRounds;
    while(1){
        if(h1-(minRounds*a2)<=0){
            v=abs(h1-(minRounds*a2));
            minHeals=(int)floor((float)v/c1) + 1;

            minHealsTot=minHealsTot+minHeals;
            minRounds = minRounds + minHeals;
            h1=h1+(minHeals*c1);
        }else{
            break;
        }
    }
    cout<<minHealsTot+save+1<<"\n";
    for(int i=0;i<minHealsTot;i++){
        cout<<"HEAL\n";
    }
    for(int i=0;i<save+1;i++){
        cout<<"STRIKE\n";
    }
    return 0;
}
