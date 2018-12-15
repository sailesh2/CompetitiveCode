#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,d;
    long long int suma=0,sumb=0;
    vector<int> a;
    vector<int> b;
    cin>>n;
    if(n==2){
        cout<<"1\n";
        cout<<"1 1";
    }else if(n==3){
        cout<<"0\n";
        cout<<"1 3";
    }else{
        if(n%2==0){
            int i=1,j=n;
            while(i<j){
                a.push_back(i);

                i++;
                if(i<=j)
                    b.push_back(i);
                if(j>i)
                    a.push_back(j);
                j--;
                if(j>i)
                    b.push_back(j);

                i++;
                j--;
            }
            suma=0;
            sumb=0;
            for(int k=0;k<a.size();k++){
                suma=suma+a[k];
            }

            for(int k=0;k<b.size();k++){
                sumb=sumb+b[k];
            }
            cout<<abs(suma-sumb)<<"\n";
            cout<<a.size()<<" ";
            for(int k=0;k<a.size();k++){
                cout<<a[k]<<" ";
            }
        }else{
            int i=2,j=n;
            while(i<j){
                a.push_back(i);

                i++;
                if(i<=j)
                    b.push_back(i);
                if(j>i)
                    a.push_back(j);
                j--;
                if(j>i)
                    b.push_back(j);
                i++;
                j--;
            }
            suma=0;
            sumb=0;
            for(int k=0;k<a.size();k++){
                suma=suma+a[k];
            }

            for(int k=0;k<b.size();k++){
                sumb=sumb+b[k];
            }
            d=abs(suma-sumb);
            if(d==0){
                cout<<"1\n";
                cout<<a.size()<<" ";
                for(int k=0;k<a.size();k++){
                    cout<<a[k]<<" ";
                }
            }
            else if(d==1){
                cout<<"0\n";
                if(suma>sumb){
                cout<<a.size()<<" ";
                for(int k=0;k<a.size();k++){
                    cout<<a[k]<<" ";
                }
                }else{
                cout<<b.size()<<" ";
                for(int k=0;k<b.size();k++){
                    cout<<b[k]<<" ";
                }
                }
            }else{
                cout<<d-1<<"\n";

                if(suma>sumb){
                cout<<a.size()<<" ";
                for(int k=0;k<a.size();k++){
                    cout<<a[k]<<" ";
                }
                }else{
                cout<<b.size()<<" ";
                for(int k=0;k<b.size();k++){
                    cout<<b[k]<<" ";
                }
                }
            }
        }
    }
    return 0;
}
