#include<bits/stdc++.h>

using namespace std;

bool comp(pair<double,long long int> a, pair<double,long long int> b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

int main(){
    long long int n,h,c,t;
    cin>>n;
    for(long long int i=0;i<n;i++){
        cin>>h>>c>>t;

        double ev = (double)(h+c)/2;

        if((h+c)!=2*t){
            long long int k = (t-h)/(h+c-2*t);
            if(k<0){
                k=0;
            }
            vector<pair<double,long long int>> v;
            v.push_back(make_pair(abs(ev-t),2));
            double odd1 = (double)((k+1)*h+k*c)/(2*k+1);
            v.push_back(make_pair(abs(odd1-t),2*k+1));
            k++;
            double odd2 = (double)((k+1)*h+k*c)/(2*k+1);
            v.push_back(make_pair(abs(odd2-t),2*k+1));

            if(k-2>=0){
                k=k-2;
                double odd3 = (double)((k+1)*h+k*c)/(2*k+1);
                v.push_back(make_pair(abs(odd3-t),2*k+1));

            }

            sort(v.begin(),v.end(),comp);
            cout<<v[0].second<<"\n";
        }else{
            cout<<"2\n";
        }

    }
    return 0;
}
