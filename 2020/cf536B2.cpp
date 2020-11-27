#include<bits/stdc++.h>

using namespace std;

struct Dish{
    int ind;
    int cost;
    int cnt;
};
int n;

bool dishComp(Dish a, Dish b){
    if(a.cost == b.cost){
        return a.ind<b.ind;
    }
    return a.cost<b.cost;
}


int main(){
    int m,a,c;
    cin>>n>>m;

    vector<Dish> dishes;
    for(int i=0;i<n;i++){
        cin>>a;
        Dish dish;
        dish.ind=i+1;
        dish.cnt=a;

        dishes.push_back(dish);
    }
    int has[n+1];
    for(int i=0;i<n;i++){
        cin>>c;
        dishes[i].cost = c;
    }

    sort(dishes.begin(),dishes.end(),dishComp);

    for(int i=0;i<n;i++){
        has[dishes[i].ind]=i;
    }

    int t,d,btindex,cnti;
    long long int sm;
    int saveIndex=0;
    for(int i=0;i<m;i++){
        cin>>t>>d;
        btindex = has[t];
        if(dishes[btindex].cnt>=d){
            sm=(long long int)dishes[btindex].cost*d;
            dishes[btindex].cnt = dishes[btindex].cnt-d;
        }else{
            sm=(long long int)dishes[btindex].cost*dishes[btindex].cnt;
            d=d-dishes[btindex].cnt;
            dishes[btindex].cnt = 0;
            cnti=0;
            while(saveIndex<n){
                if(dishes[saveIndex].cnt<d){
                    d=d-dishes[saveIndex].cnt;
                    sm=sm+(long long int)dishes[saveIndex].cost*dishes[saveIndex].cnt;
                    dishes[saveIndex].cnt=0;
                }else{
                    sm=sm+(long long int)dishes[saveIndex].cost*d;
                    dishes[saveIndex].cnt=dishes[saveIndex].cnt-d;
                    cnti=1;
                    break;
                }
                saveIndex++;
            }
            if(cnti==0)
                sm=0;
        }
        cout<<sm<<"\n";
    }

    return 0;
}
