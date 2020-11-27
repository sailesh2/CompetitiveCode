#include<bits/stdc++.h>

using namespace std;
long long int gcd(long long int a , long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
long long int lcm(long long int a, long long int b){
    return (a*b)/gcd(a,b);
}

pair<long long int,long long int> minTwo(pair<long long int,long long int> f, pair<long long int,long long int> s){
    if(f.first<s.first){
        return f;
    }else{
        return s;
    }
}

vector<pair<long long int,long long int> > minThree(pair<long long int,long long int> f,
                                                    pair<long long int,long long int> s,
                                                    pair<long long int,long long int> t){

    vector<pair<long long int,long long int> > v;
    if(f.first<s.first && f.first<t.first){
        v.push_back(f);
        v.push_back(minTwo(s,t));
    }else if(s.first<f.first && s.first<t.first){
        v.push_back(s);
        v.push_back(minTwo(f,t));
    }else{
        v.push_back(t);
        v.push_back(minTwo(f,s));
    }
    return v;
}

int main(){
    long long int n;
    cin>>n;
    long long int arr[n];

    long long int l;
    long long int a,b;
    long long int pos1,pos2;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    a=arr[0];
    pos1=1;
    b=arr[1];
    pos2=2;
    l=lcm(a,b);

    long long int l1,l2;

    for(long long int i=2;i<n;i++){
        l1=lcm(arr[i],a);
        l2=lcm(arr[i],b);
        if(l1<l2){
            if(l1<l){
                l=l1;
                b=arr[i];
                pos2=i+1;
            }else if(l1==l){
                vector<pair<long long int,long long int> > v=minThree(make_pair(a,pos1),make_pair(b,pos2),make_pair(arr[i],i+1));
                a=v[0].first;
                pos1=v[0].second;

                b=v[1].first;
                pos2=v[1].second;
            }
        }else{
            if(l2<l){
                l=l2;
                a=arr[i];
                pos1=i+1;
            }else if(l2==l){
                vector<pair<long long int,long long int> > v=minThree(make_pair(a,pos1),make_pair(b,pos2),make_pair(arr[i],i+1));
                a=v[0].first;
                pos1=v[0].second;

                b=v[1].first;
                pos2=v[1].second;
            }
        }
    }
    cout<<min(pos1,pos2)<<" "<<max(pos1,pos2);
    return 0;
}
