class Solution {
private:
    struct node{
        int ind;
        struct node* next;
        struct node* prev;
    };

public:
    int longestConsecutive(vector<int>& nums) {
        map<int,struct node *> dp;
        map<int,struct node *>::iterator dpIt;
        struct node *p;
        for(int i=0;i<nums.size();i++){
            dpIt=dp.find(nums[i]);
            if(dpIt==dp.end()){
                p=(struct node *)malloc(sizeof(struct node));
                p->ind=i;
                p->next=NULL;
                p->prev=NULL;

                dpIt=dp.find(nums[i]-1);
                if(dpIt!=dp.end()){
                    dpIt->second->next=p;
                    p->prev=dpIt->second;
                }

                dpIt=dp.find(nums[i]+1);
                if(dpIt!=dp.end()){
                    dpIt->second->prev=p;
                    p->next=dpIt->second;
                }

                dp.insert(make_pair(nums[i],p));
            }
        }

        int has[100005]={0};
        int maxi=0,ctr;
        for(int i=0;i<nums.size();i++){
            if(has[i]==0){
                ctr=0;
                p=(dp.find(nums[i]))->second;
                while(p!=NULL){
                    has[p->ind]=1;
                    p=p->next;
                    ctr++;
                }
                p=(dp.find(nums[i]))->second;
                p=p->prev;
                while(p!=NULL){
                    has[p->ind]=1;
                    p=p->prev;
                    ctr++;
                }
                maxi=max(maxi,ctr);
            }
        }
        return maxi;
    }
};
