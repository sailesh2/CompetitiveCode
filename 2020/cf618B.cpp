#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    int n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int arr[2*n];
        for(int j=0;j<2*n;j++){
            cin>>arr[j];
        }
        sort(arr,arr+2*n);
        vector<int> left,right;

        for(int j=0;j<2*n;j++){
            if(j==2*n-1){
                if(n%2==0){

                    if(j%2!=0)
                        left.push_back(arr[j]);
                    else
                        right.push_back(arr[j]);
                }else{

                    if(j%2==0)
                        left.push_back(arr[j]);
                    else
                        right.push_back(arr[j]);
                }
            }else{
                if(j%2==0)
                    left.push_back(arr[j]);
                else
                    right.push_back(arr[j]);
            }
        }

        cout<<abs(left[left.size()/2] - right[right.size()/2])<<"\n";
    }
    return 0;
}
