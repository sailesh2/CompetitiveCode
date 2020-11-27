#include<bits/stdc++.h>

using namespace std;

struct Order{
    int type;
    int posI;
    int posJ;
};

vector<Order> orders;
int n;
int finalV;

void makeEquals(int pos, int* arr, int* has){
    if(pos-1>=0 && has[pos-1]==0){
        has[pos-1]=1;
        if(arr[pos-1]!=finalV){
            Order order;
            order.posI=pos-1;
            order.posJ=pos;

            if(arr[pos-1]<finalV){
                order.type=1;
            }else{
                order.type=2;
            }
            orders.push_back(order);
        }
        makeEquals(pos-1,arr,has);
    }

    if(pos+1<n && has[pos+1]==0){
        has[pos+1]=1;
        if(arr[pos+1]!=finalV){
            Order order;
            order.posI=pos+1;
            order.posJ=pos;

            if(arr[pos+1]<finalV){
                order.type=1;
            }else{
                order.type=2;
            }
            orders.push_back(order);
        }
        makeEquals(pos+1,arr,has);
    }
}

int main(){
    cin>>n;
    int arr[n];
    int ctr[200005]={0};
    int maxi=0,save=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ctr[arr[i]]++;
        if(ctr[arr[i]]>maxi){
            maxi=ctr[arr[i]];
            save=i;
        }
    }

    int has[200005]={0};
    has[save]=1;
    finalV=arr[save];
    makeEquals(save,arr,has);
    cout<<orders.size()<<"\n";
    for(int i=0;i<orders.size();i++){
        cout<<orders[i].type<<" "<<orders[i].posI+1<<" "<<orders[i].posJ+1<<"\n";
    }
    return 0;
}
