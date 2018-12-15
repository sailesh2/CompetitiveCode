#include<bits/stdc++.h>

using namespace std;


int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}



int main(){
    int n,g;
    cin>>n;
    int arr[2*n];
    set<int> st;
    for(int i=0;i<2*n;i++){
        cin>>arr[i];

        st.insert(arr[i]);
        i++;
        arr[i]=arr[0];

    }
    int cnt=0;
    for(int i=0;i<2*n;i++){
        g=arr[i];
        for(int j=i;j<2*n;j++){
            g=gcd(g,arr[j]);
            if(st.count(g)==0){
                cnt=1;
                break;
            }
        }
        if(cnt==1)
            break;
    }
    if(cnt==1){
        cout<<"-1";
    }else{
        cout<<2*n<<"\n";
        for(int i=0;i<2*n;i++){
            cout<<arr[i]<<" ";
        }
    }

    return 0;
}
