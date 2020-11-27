#include<bits/stdc++.h>

using namespace std;

int n;

int left(int taken,int start, int endi,int* arr){

    int ln=0;
    for(int i=start;i<endi;i++){
        if(arr[i]>taken){
            taken=arr[i];
            ln++;
        }else{
            break;
        }
    }
    return ln;
}


int right(int taken,int endi, int start,int* arr){

    int ln=0;
    for(int i=endi;i>start;i--){
        if(arr[i]>taken){
            taken=arr[i];
            ln++;
        }else{
            break;
        }
    }
    return ln;
}

int main(){
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int taken=0;
    string ans="";
    for(int i=0,j=n-1;i<=j;){
        if(taken<arr[i] && taken<arr[j])
        {
            if(arr[i]==arr[j] && i<j){

                int l=left(taken,i,j,arr);
                int r=right(taken,j,i,arr);
                int maxi=max(l,r);
                char sm=l>r?'L':'R';
                for(int j=0;j<maxi;j++){
                    ans.push_back(sm);
                }

                break;
            }
            else if(arr[i]<arr[j]){
                taken=arr[i];
                i++;
                ans.push_back('L');
            }else{
                taken=arr[j];
                j--;
                ans.push_back('R');
            }
        }else if(taken<arr[i]){
                taken=arr[i];
                i++;
                ans.push_back('L');

        }else if(taken<arr[j]){
                taken=arr[j];
                j--;
                ans.push_back('R');
        }else{
            break;
        }

    }
    cout<<ans.length()<<"\n";
    cout<<ans;
    return 0;
}
