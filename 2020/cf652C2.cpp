#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;
};

Node* createNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->val=v;
    p->next=NULL;
    p->prev=NULL;
    return p;
}

Node* createList(int* arr, int n){

    Node* q=NULL;
    Node* head=NULL;
    for(int i=0;i<n;i++){
        int v = arr[i];
        Node* p = createNode(v);
        if(q!=NULL){
            q->next=p;
            p->prev=q;
        }else{
            head=p;
        }
        q=p;
    }

    return head;
}

int swaps(int* arr, int n){
    Node* head = createList(arr,n);

    Node* has[n];
    Node* p=head;
    while(p!=NULL){
        has[p->val]=p;
        p=p->next;
    }

    int ctr=0;
    p=head;
    while(p!=NULL){
        int pos=p->prev==NULL?1:p->prev->val+1;
        Node* q1 = has[pos];
        if(q1==p){
            p=p->next;
        }else{
            Node* q2=q1;
            while(q2->next!=NULL){

                if(q2->next->val==q2->val+1){
                    q2=q2->next;
                }else{
                    break;
                }
            }

            // delete
            if(q1->prev!=NULL)
                q1->prev->next=q2->next;
            if(q2->next!=NULL)
                q2->next->prev=q1->prev;

            // insert
            if(p->prev!=NULL)
                p->prev->next=q1;
            q1->prev=p->prev;
            q2->next=p;
            p->prev=q2;

            ctr++;
        }
    }

    return ctr;
}

bool sorted(int f, int s, int* arr){
    for(int i=f+1;i<=s;i++){
        if(arr[i]<arr[i-1])
            return false;
    }
    return true;
}

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int arr[n];
        int x;
        int ctr=0;
        int save=-1;
        for(int j=0;j<n;j++){
            cin>>x;
            arr[j]=x;
            if(x!=j+1){
                if(save==-1)
                    save=j;
            }else{
                if(save!=-1){
                    if(!sorted(save,j-1,arr)){

                        sort(arr+save,arr+j);
                        ctr++;
                    }
                }
                save=-1;
            }
        }
        if(save!=-1){
            if(!sorted(save,n-1,arr)){

                sort(arr+save,arr+n);
                ctr++;
            }
        }

        cout<<ctr+swaps(arr,n)<<"\n";
    }
    return 0;
}
