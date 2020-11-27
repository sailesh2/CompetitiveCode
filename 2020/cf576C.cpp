#include<bits/stdc++.h>

#define gc getchar

using namespace std;

inline long long int lscan()
{
long long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

int main(){
    long long int n,I;
    long long int distCnt=0;
    n=lscan();
    I=lscan();
    I=8*I;
    long long int d = (long long int)pow(2,(long long int)I/n);

    long long int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=lscan();
    }
    map<long long int,long long int> backHas;
    map<long long int,long long int>::iterator backHasIt;

    map<long long int,long long int> frontHas;
    map<long long int,long long int>::iterator frontHasIt;

    map<long long int,long long int> insideHas;
    map<long long int,long long int>::iterator insideHasIt;

    for(int i=n-1;i>=0;i--){
        backHasIt=backHas.find(arr[i]);
        long long int cnt=0;
        if(backHasIt!=backHas.end()){
            cnt=backHasIt->second;
            backHas.erase(backHasIt);
        }
        cnt++;
        backHas.insert(make_pair(arr[i],cnt));
    }

    long long int first=0,last=0;
    long long int mini=n-1;
    long long int frontCnt,insideCnt,backCnt;
    while(first<n && last<n){
        frontCnt=0;
        if(first-1>=0){
       //     cout<<first<<" "<<last;
            frontHasIt=frontHas.find(arr[first-1]);
            if(frontHasIt!=frontHas.end()){
                frontCnt=frontHasIt->second;
                frontHas.erase(frontHasIt);
            }
            frontCnt++;
            frontHas.insert(make_pair(arr[first-1],frontCnt));

            insideHasIt=insideHas.find(arr[first-1]);
            insideCnt=insideHasIt->second;
            insideHas.erase(insideHasIt);
            insideCnt--;
            if(insideCnt==0)
                distCnt--;
            else
                insideHas.insert(make_pair(arr[first-1],insideCnt));


        }
        frontCnt=0;
        frontHasIt=frontHas.find(arr[first]);
        if(frontHasIt!=frontHas.end()){
            frontCnt=frontHasIt->second;
        }

        while(last<n && distCnt<=d){

            insideCnt=0;
            insideHasIt = insideHas.find(arr[last]);
            if(insideHasIt==insideHas.end()){
                distCnt++;
            }else{
                insideCnt = insideHasIt->second;
                insideHas.erase(insideHasIt);
            }
            insideCnt++;
            insideHas.insert(make_pair(arr[last],insideCnt));
            if(distCnt>d){
                insideHasIt = insideHas.find(arr[last]);
                insideHas.erase(insideHasIt);
                distCnt--;
                break;
            }

            backHasIt=backHas.find(arr[last]);
            backCnt=backHasIt->second;
            backHas.erase(backHasIt);
            backCnt--;
            backHas.insert(make_pair(arr[last],backCnt));
            long long int totRight = n-last-1 - backCnt;

            long long int totLeft = first - frontCnt;

            mini=min(mini,totLeft+totRight);
         //   cout<<mini<<"--"<<frontCnt<<"+";
            last++;
        }

        first++;
        if(first>last){
            last=first;
        }
    }

    cout<<mini;

    return 0;
}
