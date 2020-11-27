#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    int pos[n+1];
    struct Node* q=NULL;
    struct Node* has[200005];
    set<pair<int,int> > st;
    set<pair<int,int> >::iterator stIt;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        struct Node* node;
        node = (struct Node*)malloc(sizeof(struct Node));
        node->data=arr[i];
        if(q!=NULL)
            q->right=node;
        node->left=q;
        node->right=NULL;
        q=node;

        st.insert(make_pair(arr[i],i));
        has[i]=node;
        pos[arr[i]]=i;
    }
    int teams[n+1];
    int team=0;
    while(st.size()>0){
        stIt = st.end();
        stIt--;
        struct Node* n = has[stIt->second];
        struct Node* prev=n->left;
        struct Node* next=n->right;
        teams[stIt->second]=team;
        //cout<<stIt->second<<"d";
        st.erase(stIt);
        int ctr=0;
        while(prev!=NULL && ctr<k){

            stIt=st.find(make_pair(prev->data,pos[prev->data]));
            teams[stIt->second]=team;
            st.erase(stIt);
            ctr++;
            prev=prev->left;
        }
        ctr=0;
        while(next!=NULL && ctr<k){

            stIt=st.find(make_pair(next->data,pos[next->data]));
            teams[stIt->second]=team;
            st.erase(stIt);
            ctr++;
            next=next->right;
        }

        if(prev!=NULL){
            prev->right=next;
        }

        if(next!=NULL){
            next->left=prev;
        }

        team=1-team;
//cout<<"co";
    }

    for(int i=0;i<n;i++){
        cout<<teams[i]+1;
    }

    return 0;
}
