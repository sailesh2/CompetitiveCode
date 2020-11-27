#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int,long long int> even;
    map<int,long long int>::iterator evenIt;
    map<int,long long int> odd;
    map<int,long long int>::iterator oddIt;
    even.insert(make_pair(0,1));
    int x=0;
    long long int c,sm=0;
    for(int i=0;i<n;i++){
        x=x^arr[i];
        if((i+1)%2==0){
            evenIt=even.find(x);
            c=0;
            if(evenIt!=even.end()){
                c=evenIt->second;
                even.erase(evenIt);
            }
            sm=sm+c;
            c++;
            even.insert(make_pair(x,c));
        }else{
            oddIt=odd.find(x);
            c=0;
            if(oddIt!=odd.end()){
                c=oddIt->second;
                odd.erase(oddIt);
            }
            sm=sm+c;
            c++;
            odd.insert(make_pair(x,c));

        }
    }
    cout<<sm;
    return 0;
}
