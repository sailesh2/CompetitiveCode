#include<bits/stdc++.h>

using namespace std;

int getMaxSeg(int a, int b, int n, int maxA, int* arr){
    int ctr=0;
    for(int i=1;i<n;i++){
        if(a==0 && b==0){
            break;
        }
        if(arr[i]==0){
            if(a>0){
                a--;
            }else{
                b--;
            }
        }else{
            if(a==maxA){
                a--;
            }
            else if(b>0){
                b--;
                a++;
            }else{
                a--;
            }
        }
        ctr=i;
    }

    return ctr+1;
}

int main(){

    int n,b,a;
    cin>>n>>b>>a;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<max(getMaxSeg(a-1,b,n,a,arr),getMaxSeg(a,b-1,n,a,arr));
    return 0;
}
