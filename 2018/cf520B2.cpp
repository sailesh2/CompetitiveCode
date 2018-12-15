#include<bits/stdc++.h>

using namespace std;

map<int,pair<int,int> > lastValMap;


map<int,pair<int,int> >::iterator lastValMapIt;
map<int,pair<int,int> >::iterator lastValMapNewIt;


void checkAndInsert(int orig, int ins, int add){

    int lastVal,lastValCtr,lastValNew,lastValCtrNew;

    lastValMapIt = lastValMap.find(orig);
    lastVal = (lastValMapIt->second).first;
    lastValCtr = (lastValMapIt->second).second;

    lastValMapNewIt = lastValMap.find(ins);
    if(lastValMapNewIt==lastValMap.end()){
      lastValMap.insert(make_pair(ins,make_pair(lastVal,lastValCtr+add)));
    }else{
        lastValNew = (lastValMapNewIt->second).first;
        lastValCtrNew = (lastValMapNewIt->second).second;

        if((lastVal < lastValNew) || (lastValNew == lastVal && lastValCtr+add < lastValCtrNew)){
            lastValMap.erase(lastValMapNewIt);
            lastValMap.insert(make_pair(ins,make_pair(lastVal,lastValCtr+add)));

        }
    }
}

int main(){

    int n,lastVal,lastValCtr,lastValNew,lastValCtrNew;
    cin>>n;
    if(n==1){
        cout<<"1 0";
    }else{

        int one,sec;
        for(int i=2;i<=100000;i++){
            if(lastValMap.find(i)==lastValMap.end()){
                lastValMap.insert(make_pair(i,make_pair(i,0)));
            }
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    one=j;
                    sec=i/j;
                    if(one==1){
                        checkAndInsert(i,i*i,1);
                    }else{
                        if(one!=sec){
                            checkAndInsert(i,i*one,2);
                            checkAndInsert(i,i*sec,2);
                        }else{
                            checkAndInsert(i,i*one,2);
                        }
                    }
                }
            }
        }

        lastValMapIt = lastValMap.find(n);
        if(lastValMapIt==lastValMap.end()){
            lastVal=n;
            lastValCtr=0;
        }else{
            lastVal = (lastValMapIt->second).first;
            lastValCtr = (lastValMapIt->second).second;
        }
        cout<<lastVal<<" "<<lastValCtr;
    }

    return 0;
}
