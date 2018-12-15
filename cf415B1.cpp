#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n,f,a,b;
    cin>>n>>f;
    vector<long long int> pro;
    long long int s = 0;
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        if(b>a){
            pro.push_back(min(2*a,b) - min(a,b));
        }

        s = s + min(a,b);
    }

    sort(pro.begin(),pro.end());

    int pos;
    for(int i = 0;i<f;i++){
        pos = pro.size()-1-i;
        if(pos<0)
            break;
        s = s + pro.at(pos);
    }

    cout<<s;

    return 0;
}
