#include<stdio.h>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[k];
    int sm=0;
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }

    int middle = 4*n;
    for(int i=0;i<k;i++){
        if(arr[i]%2==0){
            while(middle>0 && arr[i]>=4){
                middle = middle-4;
                arr[i]=arr[i]-4;
                sm=sm+4;
            }
        }
    }

    int save=-1,save2=-1;
    while(middle>0){
            save=-1;save2=-1;
        for(int i=0;i<k;i++){
            if(arr[i]%2==0 && arr[i]>0){
                save=i;
            } else if(arr[i]%2!=0){
                save2=i;
            }
        }

        if(save!=-1 && save2!=-1){
            arr[save]=arr[save]-2;
            arr[save2]=arr[save2]-1;
            sm=sm+4;
            middle =middle-4;
        } else if(save==-1 && save2!=-1){
            arr[save2]=arr[save2]-1;
            sm=sm+4;
            middle =middle-4;
        } else if(sav2==-1 && save!=-1){

        }
         else {
            break;
        }
    }

    for(int i=0;i<k;i++){

        sm = sm+arr[i];

        if(arr[i]%2!=0){
            sm++;
        }
    }


    if(sm<=8*n){
        cout<<"YES";
    } else {
        cout<<"NO";
    }
    return 0;
}
