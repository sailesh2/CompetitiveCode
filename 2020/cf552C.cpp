#include<bits/stdc++.h>

using namespace std;

int Fish(int frem){
    if(frem==0){
        return 0;
    }else if(frem==1){
        return 4;
    }else{
        return 7;
    }
}

int Rabbit(int frem){
    if(frem==0){
        return 0;
    }else{
        return 2;
    }
}

int Chicken(int frem){
    if(frem==0){
        return 0;
    }else {
        return 3;
    }
}

vector<string> getPerWeeks(){
 string catWeek1="FRCFCRF";
 string catWeek2="RCFCRFF";
 string catWeek3="CFCRFFR";
 string catWeek4="FCRFFRC";
 string catWeek5="CRFFRCF";
 string catWeek6="RFFRCFC";
 string catWeek7="FFRCFCR";

 vector<string> weeks;
 weeks.push_back(catWeek1);
 weeks.push_back(catWeek2);
 weeks.push_back(catWeek3);
 weeks.push_back(catWeek4);
 weeks.push_back(catWeek5);
 weeks.push_back(catWeek6);
 weeks.push_back(catWeek7);

 return weeks;
}

int getMaxDays(string catWeek, int f, int r, int c){


    int weekGone = min(f/3, min(r/2,c/2));
    f = f - 3*weekGone;
    r = r - 2*weekGone;
    c = c - 2*weekGone;

    int ctr=0;
    int fDays = weekGone*7;

    for(int i=0;i<7;i++){

        if(catWeek[i]=='F' ){
            if(f==0)
                break;
            f--;
            ctr++;
        }

        if(catWeek[i]=='C'){
            if(c==0)
                break;
            c--;
            ctr++;
        }

        if(catWeek[i]=='R'){
            if(r==0)
                break;
            r--;
            ctr++;
        }
    }
    return fDays+ctr;
}

int main(){
    int f,r,c;
    cin>>f>>r>>c;
    vector<string> perWeeks = getPerWeeks();
    int maxi=0;
    for(int i=0;i<perWeeks.size();i++){
        maxi=max(maxi,getMaxDays(perWeeks[i],f,r,c));
    }
    cout<<maxi;

    return 0;
}
