#include<bits/stdc++.h>

using namespace std;

int n;
int sibl[200005];
int tree1[200005];
int tree2[200005];
int done=0,child=1,cnt=1;
void constructNonIsoTrees(int level, int parent,int parent1){
    int p1,p2=parent1;
    if(level==n+1)
        return;
    if(cnt==1){
        if(sibl[level]==1){
            cnt=1;
            tree1[child]=parent;
            tree2[child]=parent;
            p1 =child;
            child++;

        }else if(sibl[level]>=2){
            cnt=2;
            p1=child;
            p2=child+1;
            for(int i=0;i<sibl[level];i++){

                tree1[child]=parent;
                tree2[child]=parent;
                child++;
            }

        }
    }else {
        if(done==0){
            if(sibl[level]>=2){
                tree1[child]=parent;
                tree2[child]=parent1;
                p1=child;
                child++;
                for(int i=1;i<sibl[level];i++){

                    tree1[child]=parent;
                    tree2[child]=parent;
                    child++;
                }
                done=1;
            }else{
                cnt=1;
                p1=child;
                tree1[child]=parent;
                tree2[child]=parent;
                child++;

            }
        }else{
            p1=child;
            for(int i=0;i<sibl[level];i++){

                tree1[child]=parent;
                tree2[child]=parent;
                child++;
            }
            done=1;
        }
    }
    constructNonIsoTrees(level+1,p1,p2);
}
int main(){
    cin>>n;
    for(int i=0;i<n+1;i++){
        cin>>sibl[i];
    }
    int p=0,l=0;

    constructNonIsoTrees(l,p,p);
    if(done==0){
        cout<<"perfect";
    }else{
        cout<<"ambiguous\n";

        for(int i=1;i<child;i++){
            cout<<tree1[i]<<" ";
        }
        cout<<"\n";
        for(int i=1;i<child;i++){
            cout<<tree2[i]<<" ";
        }
    }
    return 0;
}
