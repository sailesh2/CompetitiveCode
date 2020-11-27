N#include<bits/stdc++.h>

using namespace std;

struct Dish{
    int ind;
    int cost;
    int cnt;
};
int n,saveIndex=1;
vector<Dish> BTree;

bool dishComp(Dish a, Dish b){
    if(a.cost == b.cost){
        return a.ind<b.ind;
    }
    return a.cost<b.cost;
}

int getSum(int index)
{
    int sum = 0;


    while (index>0)
    {
        sum += (BTree[index].cost * BTree[index].cnt);

        index -= index & (-index);
    }
    return sum;
}

int getCnt(int index)
{
    int sum = 0;


    while (index>0)
    {
        sum += (BTree[index].cnt);

        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int index, int nval)
{
    index = index + 1;

    int val = nval - (getCnt(index) - getCnt(index-1));
    while (index <= n)
    {
        BTree[index].cnt += val;

        index += index & (-index);
    }
}



int binSear(int dishreq){
    int ctr=1;
    int save=saveIndex-1;
    int save2=saveIndex-1;

    while(1){
        while(save+ctr<=n && ((getCnt(save+ctr) - getCnt(saveIndex-1))<dishreq)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save;
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

    for(int i=0;i<n;i++){
        cin>>c;
        dishes[i].cost = c;
    }

    sort(dishes.begin(),dishes.end(),dishComp);

    for(int i=0;i<=n;i++){
        Dish dish;
        dish.ind=0;
        dish.cost=0;
        dish.cnt=0;
        BTree.push_back(dish);
    }

    int has[n+1];
    for(int i=0;i<n;i++){
        has[dishes[i].ind]=i+1;
        BTree[i+1].cost = dishes[i].cost;
        BTree[i+1].ind = dishes[i].ind;
        updateBIT(i,dishes[i].cnt);
    }

    int t,d,btindex;
    int sm,cnti;
    for(int i=0;i<m;i++){
        cin>>t>>d;
        sm=0;
        btindex = has[t];
        if(saveIndex<=n){
            if(btindex>=saveIndex){
                cnti = getCnt(btindex) - getCnt(btindex-1);
                //cout<<BTree[btindex].cnt<<"\n";
                if(cnti>=d){
                    sm=BTree[btindex].cost*d;
                    updateBIT(btindex,cnti - d);
                }else{
                    d=d-cnti;
                    sm=BTree[btindex].cost*cnti;
                    updateBIT(btindex,0);
                    cout<<btindex<<":"<<cnti<<"-";
                    int newSaveIndex = binSear(d);
                    cout<<newSaveIndex;
                    int cntRem=d;
                    if(newSaveIndex>=saveIndex){
                    sm=sm+getSum(newSaveIndex) - getSum(saveIndex - 1);
                    cntRem = d - (getCnt(newSaveIndex) - getCnt(saveIndex - 1));
                    saveIndex = newSaveIndex;
                    }
                    sm=sm+BTree[saveIndex].cost*cntRem;
                    updateBIT(saveIndex,(getCnt(saveIndex) - getCnt(saveIndex-1))-cntRem);
                }
            }else{
                    int newSaveIndex = binSear(d);
                    cout<<newSaveIndex;
                    int cntRem=d;
                    if(newSaveIndex>=saveIndex){
                    sm=sm+getSum(newSaveIndex) - getSum(saveIndex - 1);
                    cntRem = d - (getCnt(newSaveIndex) - getCnt(saveIndex - 1));
                    saveIndex = newSaveIndex;
                    }
                    sm=sm+BTree[saveIndex].cost*cntRem;
                    updateBIT(saveIndex,(getCnt(saveIndex) - getCnt(saveIndex-1))-cntRem);
            }
        }
        cout<<sm<<"\n";
    }

    return 0;
}
