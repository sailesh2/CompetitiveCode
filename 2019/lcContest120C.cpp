/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int minDis,save;
    int ans=0;
    pair<int,int> graph[105][3];
    int coints[105];
    int cloneTree(int parent, TreeNode* root, int ind){
        if(root==NULL)
            return 0;
        coins[ind]=root->val;
        graph[ind][0] = parent;
        graph[ind][1] = cloneTree(ind, root->left, ind+1);
        graph[ind][2] = cloneTree(ind, root->left, ind+2);
        return ind;
    }

    void distribute(int root, int* has, int dis){
        if(coins[root]==0){
            if(dis<minDis){
                minDis=dis;
                save=root;
            }
            return;
        }
        for(int i=0;i<3;i++){
            if(graph[root][i]!=0){
            if(has[graph[root][i]]==0){
                has[graph[root][i]]=1;
                distribute(graph[root][i],has,dis+1);
                has[graph[root][i]]=0;
            }
            }
        }
    }

    void minDistributeCoins(int root, int* has){
        while(coins[root]>1){
            int has2[105]={0};
            minDis=100000;
            save=-1;
            distribute(root,has2,0);
            ans=ans+minDis;
            coins[save]=1;
        }
        for(int i=0;i<3;i++){
            if(graph[root][i]!=0){
                if(has[graph[root][i]]==0){
                    has[graph[root][i]]=1;
                    minDistributeCoins(graph[root][i],has);
                    has[graph[root][i]]=0;
                }
            }
        }
    }

public:
    int distributeCoins(TreeNode* root) {
        cloneTree(0,root,1);
        int has[105]={0};
        minDistributeCoins(root,has);
        return ans;
    }
};
