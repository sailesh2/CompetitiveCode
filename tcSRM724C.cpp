#include<bits/stdc++.h>

using namespace std;

class UnfinishedTournamentEasy{
public:
    double maximal(vector<string> t){
        int ctr,n;
        double a=0,p;
        n=t.size();
        for(int i=0;i<t.size();i++){
            ctr=0;
            for(int j=0;j<t[i].length();j++){
                if(t[i][j]=='W'){
                    ctr++;
                }
            }
            if(ctr>(n/2)){
                for(int j=0;j<t[i].length();j++){
                    if(t[i][j]=='?'){
                        t[i][j]='W';
                        t[j][i]='L';
                    }
                }
                ctr=n-1;
            }else{
                for(int j=0;j<t[i].length();j++){
                    if(t[i][j]=='?'){
                        t[i][j]='L';
                        t[j][i]='W';
                    }
                }
            }
            p=((double)ctr/(n-1)-0.5);
            a=a+p*p;
        }
        return a/n;
    }
};
