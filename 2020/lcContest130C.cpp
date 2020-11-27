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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while(head!=NULL){
            nums.push_back(head->val);
            head=head->next;
        }

        int ans[nums.size()];
        int stk[nums.size()];
        int top=-1;
        for(int i=nums.size()-1;i>=0;i--){
            while(top>=0 && stk[top]<=nums[i]){
                top--;
            }
            if(top>=0){
                ans[i]=stk[top];
            }else{
                ans[i]=0;
            }
            stk[++top]=nums[i];
        }

        vector<int> ans2;
        for(int i=0;i<nums.size();i++){
            ans2.push_back(ans[i]);
        }
        return ans2;
    }
};
