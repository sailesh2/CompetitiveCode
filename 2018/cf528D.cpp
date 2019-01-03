#include<bits/stdc++.h>

using namespace std;
vector<int> tree[200005];
int diamMax = 0;
int diamMax2 = 0;
map<int,int> diamsMap;
map<int,int>::iterator diamsMapIt;
vector<int> diamsMaxVec;

int diameter(int root,int parent){
    int maxih=-1;
    int maxih2=-1;
    vector<int> subTreeHeights;
    for(int i=0;i<tree[root].size();i++){
        if(parent != tree[root][i]){
            subTreeHeights.push_back(diameter(tree[root][i],root));
        }
    }
    int save=-1;
    for(int i=0;i<subTreeHeights.size();i++){
        if(subTreeHeights[i]>maxih){
            maxih=subTreeHeights[i];
            save=i;
        }
    }
    if(save!=-1){
        for(int i=0;i<subTreeHeights.size();i++){
            if(save!=i && subTreeHeights[i]>maxih2){
                maxih2=subTreeHeights[i];
            }
        }
    }
    if(maxih+1 + maxih2+1 >= diamMax){
        diamMax=maxih+1 + maxih2+1;
        diamsMap.insert(make_pair(root,diamMax));
    }
    return maxih+1;
}

void fillGreatestDiams(int root, int parent){
    diamsMapIt = diamsMap.find(root);
    if(diamsMapIt != diamsMap.end()){
        if(diamsMapIt->second == diamMax){
            diamsMaxVec.push_back(root);
        }else{
            diamMax2 = max(diamMax2,diamsMapIt->second);
        }
    }
    for(int i=0;i<tree[root].size();i++){
        if(parent != tree[root][i]){
            fillGreatestDiams(tree[root][i],root);
        }
    }
}

int main(){
    int n,s,u,v;
    cin>>n>>s;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        tree[u-1].push_back(v);
        tree[v-1].push_back(u);
    }
    diameter(0,-1);

    fillGreatestDiams(0,-1);
    int ctr=0;
    for(int i=0;i<diamsMaxVec.size();i++){
        if(diamsMaxVec[i]!=0){
            ctr++;
            if(ctr>=2){
                break;
            }
        }
    }
    if(ctr>=2){
        cout<<(float)s/(n-1);
    }else{
        cout<<(float)s/(n-1-(diamMax - diamMax2));
    }
    return 0;
}
