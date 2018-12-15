#include<bits/stdc++.h>

using namespace std;

int minToRoom[200005];
int roomToMin[200005];

void clearRoom(){
    for(int i=0;i<200005;i++){
        minToRoom[i]=-1;
        roomToMin[i]=-1;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ctr=1,rooms=1,room;

    for(int i=0;i<n;i++){
        if(arr[i]<ctr){
            if(minToRoom[arr[i]]!=-1){
                room=minToRoom[arr[i]];
                if(roomToMin[room]==arr[i]){
                    roomToMin[room]=ctr;
                    minToRoom[ctr]=room;
                } else{
                    rooms++;
                    roomToMin[rooms]=ctr;
                    minToRoom[ctr]=rooms;
                }
            }else{
                rooms++;
                roomToMin[rooms]=ctr;
                minToRoom[ctr]=rooms;
            }
        }else{
            rooms++;
            roomToMin[rooms]=ctr;
            minToRoom[ctr]=rooms;
        }
        ctr++;
    }
    cout<<rooms;
    return 0;
}
