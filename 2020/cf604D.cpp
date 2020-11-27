#include<bits/stdc++.h>

using namespace std;
int n;
bool generateSeq(int* arr, int a, int b, int c , int d){
    int cnt=0;

    for(int i=1;i<n;i++){
        if(arr[i-1]==0){
            if(b>0){
                arr[i]=1;
                b--;
            }else{
                cnt=1;
                break;
            }
        }else if(arr[i-1]==1){
            if(a>0){
                arr[i]=0;
                a--;
            }else if(c>0){
                arr[i]=2;
                c--;
            }else{
                cnt=1;
                break;
            }

        }else if(arr[i-1]==2){
            if(b>0){
                arr[i]=1;
                b--;
            }else if(d>0){
                arr[i]=3;
                d--;
            }else{
                cnt=1;
                break;
            }
        }else{
            if(c>0){
                arr[i]=2;
                c--;
            }else{
                cnt=1;
                break;
            }
        }
    }

    return cnt==0;
}

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    n=a+b+c+d;
    int arr[n];

    if(a>0 && b>0){
        arr[0]=0;
        if(generateSeq(arr,a-1,b,c,d)){
            cout<<"YES\n";
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
        }else{
            arr[0]=1;
            if(generateSeq(arr,a,b-1,c,d)){
                cout<<"YES\n";
                for(int i=0;i<n;i++){
                    cout<<arr[i]<<" ";
                }
            }else{
                cout<<"NO";
            }
        }
    }else if(a>0){
        arr[0]=0;
        if(generateSeq(arr,a-1,b,c,d)){
            cout<<"YES\n";
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
        }else{
            cout<<"NO";
        }
    }else if(b>0){

        if(b>0 && c>0){
            arr[0]=1;
            if(generateSeq(arr,a,b-1,c,d)){
                cout<<"YES\n";
                for(int i=0;i<n;i++){
                    cout<<arr[i]<<" ";
                }
            }else{
                arr[0]=2;
                if(generateSeq(arr,a,b,c-1,d)){
                    cout<<"YES\n";
                    for(int i=0;i<n;i++){
                        cout<<arr[i]<<" ";
                    }
                }else{
                    cout<<"NO";
                }
            }
        }else if(b>0){
            arr[0]=1;
            if(generateSeq(arr,a,b-1,c,d)){
                cout<<"YES\n";
                for(int i=0;i<n;i++){
                    cout<<arr[i]<<" ";
                }
            }else{
                cout<<"NO";
            }
        }else if(c>0){

            if(c>0 && d>0){
                arr[0]=2;
                if(generateSeq(arr,a,b,c-1,d)){
                    cout<<"YES\n";
                    for(int i=0;i<n;i++){
                        cout<<arr[i]<<" ";
                    }
                }else{
                    arr[0]=3;
                    if(generateSeq(arr,a,b,c,d-1)){
                        cout<<"YES\n";
                        for(int i=0;i<n;i++){
                            cout<<arr[i]<<" ";
                        }
                    }else{
                        cout<<"NO";
                    }
                }

            }else if(c>0){
                arr[0]=2;
                if(generateSeq(arr,a,b,c-1,d)){
                    cout<<"YES\n";
                    for(int i=0;i<n;i++){
                        cout<<arr[i]<<" ";
                    }
                }else{
                    cout<<"NO";
                }

            }else if(d>0){
                arr[0]=3;
                if(generateSeq(arr,a,b,c,d-1)){
                    cout<<"YES\n";
                    for(int i=0;i<n;i++){
                        cout<<arr[i]<<" ";
                    }
                }else{
                    cout<<"NO";
                }

            }else{
                cout<<"NO";
            }

        }else{
                if(d>0){
                    arr[0]=3;
                    if(generateSeq(arr,a,b,c,d-1)){
                        cout<<"YES\n";
                        for(int i=0;i<n;i++){
                            cout<<arr[i]<<" ";
                        }
                    }else{
                        cout<<"NO";
                    }
                }else{
                    cout<<"NO";
                }

        }

    }else{
        if(c>0 && d>0){
                arr[0]=2;
                if(generateSeq(arr,a,b,c-1,d)){
                    cout<<"YES\n";
                    for(int i=0;i<n;i++){
                        cout<<arr[i]<<" ";
                    }
                }else{
                    arr[0]=3;
                    if(generateSeq(arr,a,b,c,d-1)){
                        cout<<"YES\n";
                        for(int i=0;i<n;i++){
                            cout<<arr[i]<<" ";
                        }
                    }else{
                        cout<<"NO";
                    }
                }

            }else if(c>0){
                arr[0]=2;
                if(generateSeq(arr,a,b,c-1,d)){
                    cout<<"YES\n";
                    for(int i=0;i<n;i++){
                        cout<<arr[i]<<" ";
                    }
                }else{
                    cout<<"NO";
                }

            }else if(d>0){
                arr[0]=3;
                if(generateSeq(arr,a,b,c,d-1)){
                    cout<<"YES\n";
                    for(int i=0;i<n;i++){
                        cout<<arr[i]<<" ";
                    }
                }else{
                    cout<<"NO";
                }

            }else{
                cout<<"NO";
            }
    }
    return 0;
}
