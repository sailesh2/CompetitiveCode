#include<bits/stdc++.h>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
private:
    int getLength(ListNode* root){
        int ctr=0;
        while(root!=NULL){
            ctr++;
            root=root->next;
        }
        return ctr;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len=getLength(root);
        int parts[k];
        for(int i=0;i<k;i++){
            parts[i]=len/k;
        }
        for(int i=0;i<len%k;i++)
        {
            parts[i]++;
        }
        vector<ListNode*> listParts;
        ListNode* p,*q,*part;
        for(int i=0;i<k;i++){
            p=NULL;
            if(root!=NULL){
                p=(ListNode*)malloc(sizeof(ListNode));
                p->val=root->val;
                p->next=NULL;
            }
            part=p;
            for(int j=0;j<parts[i];j++){
                q=NULL;
                if(root!=NULL){
                    root=root->next;
                    q=(ListNode*)malloc(sizeof(ListNode));
                    q->val=root->val;
                    q->next=NULL;
                    p->next=q;
                }else{
                    break;
                }
                p=q;
            }
            listParts.push_back(part);
            root=root->next;
        }
        return listParts;
    }
};
