/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)
            return NULL;

        ListNode *p,*lSum=NULL,*q;
        int sum=0,c=0,v1,v2;
        while(l1!=NULL || l2!=NULL){
            if(l1==NULL){
                v1=0;
            }else{
                v1=l1->val;
                l1=l1->next;
            }
            if(l2==NULL){
                v2=0;
            }else{
                v2=l2->val;
                l2=l2->next;
            }
            sum=v1+v2+c;
            c=sum/10;
            q=(ListNode *)malloc(sizeof(ListNode));
            q->next=NULL;
            q->val=sum%10;
            if(lSum==NULL){
                lSum=q;
            }else{
                p->next=q;
            }
            p=q;
        }
        if(c>0){
            q=(ListNode *)malloc(sizeof(ListNode));
            q->next=NULL;
            q->val=c;
            p->next=q;
        }
        return lSum;
    }
};
