#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,x;
    cin>>n;
    map<long long int,long long int> has;
    map<long long int,long long int>::iterator hasIt;

    has.insert(make_pair(0,0));
    long long int minIndex=0;
    long long int exc=0,s=0;
    for(long long int i=0;i<n;i++){
        cin>>x;
        s=s+x;
        hasIt=has.find(s);
        if(hasIt!=has.end()){

            long long int index = hasIt->second;
            index++;
            if(index>minIndex){
                long long int lr = index-(minIndex);
                long long int rr = n-i;
                exc=exc+lr*rr;
                minIndex=index;
            }
            has.erase(hasIt);
        }

        has.insert(make_pair(s,i+1));
    }

    long long int tot = (n*(n+1))/2;
    long long int rem = tot-exc;
    cout<<rem;
    return 0;
}
