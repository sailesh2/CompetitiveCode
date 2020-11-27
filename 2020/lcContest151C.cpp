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
    map<int,ListNode*> mp;
    map<int,ListNode*>::iterator mpIt;
    map<int,ListNode*>::iterator mpIt2;

    map<ListNode*,int> mpVal;
    map<ListNode*,int>::iterator mpValIt;


    ListNode* nonZeroSumList(ListNode* head){
        ListNode* curr=head;
        int sm=0;
        mp.insert(make_pair(0,(ListNode*)NULL));
        while(curr!=NULL){
            sm=sm+(curr->val);
            mpIt = mp.find(sm);
            if(mpIt!=mp.end()){
                ListNode* node = mpIt->second;
                ListNode* p;
                if(node==NULL){
                    p=head;

                }else{
                    p = node->next;
                }

                while(p!=(curr)->next){
                    int cumlVal = (mpVal.find(p))->second;
                    mpIt2 = mp.find(cumlVal);
                    if((mpIt2->first) == (long long int)p){
                        mp.erase(mpIt2);
                    }
                    p=p->next;
                }

                if(node!=NULL)
                node->next=curr->next;
                else
                head=curr->next;
            }else{
                mpIt2 = mp.find(sm);
                if(mpIt2==mp.end())
                    mp.insert(make_pair(sm,curr));
                mpVal.insert(make_pair(curr,sm));
            }
            curr=curr->next;
        }

        return head;
    }
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        return nonZeroSumList(head);
    }
};
