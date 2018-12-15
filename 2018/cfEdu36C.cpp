#include<bits/stdc++.h>

using namespace std;
long long int pTable[20];
void calculatePow(){
    long long int p=1;
    for(int i=0;i<20;i++){
        pTable[i]=p;
        p=p*10;
    }
}
long long int isPossible(int ind,vector<int> A,vector<int> B){
    if(ind==A.size())
        return 0;
    int maxi=0,save=-1,temp;
    long long int resA=0,val;
    for(int i=ind;i<A.size();i++){
        if(A[i]<=B[ind]){
            if(A[i]>=maxi){
                maxi=A[i];
                save=i;
            }
        }
    }
    vector<int> v;
    if(save==-1)
        return save;
    if(maxi<B[ind]){
        A[save]=A[ind];
        resA=resA*10+maxi;

        for(int i=ind+1;i<A.size();i++){
            v.push_back(A[i]);
        }
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--){
            resA=resA*10+v[i];
        }
        return resA;
    }else{
        temp=A[save];
        A[save]=A[ind];
        A[ind]=temp;
        val=isPossible(ind+1,A,B);
        if(val==-1){

            temp=A[save];
            A[save]=A[ind];
            A[ind]=temp;
            maxi=0;
            save=-1;
            for(int i=ind;i<A.size();i++){
                if(A[i]<B[ind]){
                    if(A[i]>=maxi){
                        maxi=A[i];
                        save=i;
                    }
                }
            }
            if(save==-1)
                return save;
            A[save]=A[ind];
            resA=resA*10+maxi;
            for(int i=ind+1;i<A.size();i++){
                v.push_back(A[i]);
            }
            sort(v.begin(),v.end());
            for(int i=v.size()-1;i>=0;i--){
                resA=resA*10+v[i];
            }
            return resA;
        }else{
            resA=A[ind]*pTable[A.size()-1-ind]+val;
            return resA;
        }
    }
}
int main(){
    long long int a,b;
    cin>>a>>b;
    vector<int> digAR;
    vector<int> digBR;

    vector<int> digA;
    vector<int> digB;

    int ctrA=0,ctrB=0;
    while(a>0){
        digAR.push_back(a%10);
        a=a/10;
        ctrA++;
    }
    for(int i=ctrA-1;i>=0;i--){
        digA.push_back(digAR[i]);
    }
    while(b>0){
        digBR.push_back(b%10);
        b=b/10;
        ctrB++;
    }
    for(int i=ctrB-1;i>=0;i--){
        digB.push_back(digBR[i]);
    }
    long long int resA=0;

    vector<int> v;
    if(ctrA<ctrB){
        sort(digA.begin(),digA.end());
        for(int i=ctrA-1;i>=0;i--){
            resA=resA*10+digA[i];
        }
        cout<<resA;
    }else{
        calculatePow();
        cout<<isPossible(0,digA,digB);
    }
    return 0;
}
