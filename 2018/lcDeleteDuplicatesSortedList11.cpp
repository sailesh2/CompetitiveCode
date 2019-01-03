/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    bool isDistinct(ListNode* head, ListNode* prev){
        bool distinct=true;
        if(head->next!=NULL){
            distinct = head->val != head->next->val;
        }
        if(prev!=NULL){
            distinct = distinct && prev->val != head->val;
        }
        return distinct;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* root=NULL,*first=NULL,*prev=NULL;
        if(head->next==NULL){
            return head;
        }
        while(head!=NULL){
            if(isDistinct(head,prev)){
                if(first==NULL){
                    root=head;
                }else{
                    first->next=head;
                }
                first=head;
            }
            prev=head;
            head=head->next;
        }
        if(first!=NULL)
            first->next=NULL;
        return root;
    }
};
