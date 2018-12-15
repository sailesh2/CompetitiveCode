#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,xo,yo,x,y;
    cin>>n>>xo>>yo;
    double inf=1000000000;
    double m;
    set<double> shotSlopes;
    for(int i=0;i<n;i++){
        cin>>x>>y;

        if(x==xo)
            shotSlopes.insert(inf);
        else{
            m=(double(yo-y))/(double(xo-x));
            shotSlopes.insert(m);
        }
    }
    cout<<shotSlopes.size();
    return 0;
}
