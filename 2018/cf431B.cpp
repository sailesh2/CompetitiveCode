#include<bits/stdc++.h>

using namespace std;

int n;

pair<bool,double> isInOneLine(vector<pair<long long int,long long int> > rest){
    if(rest.size()==0)
        return make_pair(false,-1);

    double slope;
    if(rest.size()<=2){
        slope = (double)(rest[0].second - rest[1].second)/(rest[0].first - rest[1].first);
        return make_pair(true,slope);
    }

    slope = (double)(rest[0].second - rest[1].second)/(rest[0].first - rest[1].first);

    for(int i=2;i<rest.size();i++){
        double newSlope = (double)(rest[1].second - rest[i].second)/(rest[1].first - rest[i].first);
        if(newSlope != slope)
            return make_pair(false,-1);
    }
    return make_pair(true,slope);
}

bool twopoint(long long int* y){
    double slope,newSlope;
    vector<pair<long long int,long long int> > rest;
    for(int i=1;i<n;i++){
        rest.clear();
        slope = (double)(y[i] - y[0])/i;
        for(int j=1;j<n;j++){
            if(j!=i){
                newSlope = (double)(y[j] - y[0])/j;
                if(newSlope != slope)
                    rest.push_back(make_pair(j+1,y[j]));
            }
        }
        pair<bool,double> newOneLineSlope = isInOneLine(rest);
        if(newOneLineSlope.first && newOneLineSlope.second == slope){
            return true;
        }
    }
    return false;
}

bool onepoint(long long int* y){
    vector<pair<long long int,long long int> > rest;
    for(int i=0;i<n;i++){
        rest.clear();
        for(int j=0;j<n;j++){
            if(j!=i){
                rest.push_back(make_pair(j+1,y[j]));
            }
        }
        pair<bool,double> newOneLineSlope = isInOneLine(rest);

        if(newOneLineSlope.first){
            double slope = (double)(rest[0].second -  y[i])/(rest[0].first - (i+1));
            if(newOneLineSlope.second != slope)
                return true;
        }
    }
    return false;
}

/*bool posneg(long long int* y){
    int pos=0,neg=0;
    for(int i=0;i<n;i++){
        if(y[i]>0){
            pos=1;
        }else if(y[i]<0)
        {
            neg=1;
        }
    }
    return pos==1 && neg==1;
}*/

int main(){
    cin>>n;
    long long int y[n];
    for(int i=0;i<n;i++){
        cin>>y[i];
    }

    if(onepoint(y)){
        cout<<"Yes";
    }else if(twopoint(y)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}
