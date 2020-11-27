#include<bits/stdc++.h>

using namespace std;
int n;

bool possible(int* arr){
    vector<int> left,right;

    int f=0;
    left.push_back(arr[f]);
    for(int i=f+1;i<2*n;i++){
        if(arr[i]>arr[0]){
            right.push_back(arr[i]);
            break;
        }
    }

    if(right.size()==0){
        return false;
    }

    int cnt=0;
    f++;
    while(f<2*n){
        if(cnt==0){
            if(arr[f]==right[right.size()-1]){
                int found=0;

                for(int i=f+1;i<2*n;i++){
                    if(arr[i]>arr[f]){
                        found=1;
                        left.push_back(arr[i]);
                        cnt=1;
                        break;
                    }
                }

                if(found==0)
                    return left.size()==n && right.size()==n&& f==2*n-1;
            }else{
                left.push_back(arr[f]);
            }
        }else{

            if(arr[f]==left[left.size()-1]){
                int found=0;

                for(int i=f+1;i<2*n;i++){
                    if(arr[i]>arr[f]){
                        found=1;
                        right.push_back(arr[i]);
                        cnt=0;
                        break;
                    }
                }

                if(found==0)
                    return left.size()==n && right.size()==n && f==2*n-1;
            }else{
                right.push_back(arr[f]);
            }

        }

        f++;
    }

    return left.size()==n && right.size()==n;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int arr[2*n];
        for(int j=0;j<2*n;j++){
            cin>>arr[j];
        }

        if(possible(arr)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
