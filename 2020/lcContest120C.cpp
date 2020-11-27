/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct CoinNode{
    vector<pair<int,int>> coinsAvailable;
    vector<pair<int,int>> coinsNeeded;
};

bool coinComparator(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

class Solution {
private:
    int ans=0;


    vector<pair<int,int>> mergeChildCoinsAvailable(CoinNode coinNodeLeft, CoinNode coinNodeRight){
        vector<pair<int,int>> newCoinsAvailable;
        pair<int,int> p;
        for(int i=0;i<coinNodeLeft.coinsAvailable.size();i++){
            p=make_pair(coinNodeLeft.coinsAvailable[i].first,coinNodeLeft.coinsAvailable[i].second+1);
            newCoinsAvailable.push_back(p);
        }

        for(int i=0;i<coinNodeRight.coinsAvailable.size();i++){
            p=make_pair(coinNodeRight.coinsAvailable[i].first,coinNodeRight.coinsAvailable[i].second+1);
            newCoinsAvailable.push_back(p);
        }
        return newCoinsAvailable;
    }

    vector<pair<int,int>> mergeChildCoinsNeeded(CoinNode coinNodeLeft, CoinNode coinNodeRight){
        vector<pair<int,int>> newCoinsNeeded;
        pair<int,int> p;
        for(int i=0;i<coinNodeLeft.coinsNeeded.size();i++){
            p=make_pair(coinNodeLeft.coinsNeeded[i].first,coinNodeLeft.coinsNeeded[i].second+1);
            newCoinsNeeded.push_back(p);
        }

        for(int i=0;i<coinNodeRight.coinsNeeded.size();i++){
            p=make_pair(coinNodeRight.coinsNeeded[i].first,coinNodeRight.coinsNeeded[i].second+1);
            newCoinsNeeded.push_back(p);
        }
        return newCoinsNeeded;
    }

    CoinNode minDistributeCoins(TreeNode* root){
        CoinNode coinNode;

        if(root==NULL)
            return coinNode;

        CoinNode coinNodeLeft = minDistributeCoins(root->left);
        CoinNode coinNodeRight = minDistributeCoins(root->right);

        vector<pair<int,int>> newCoinsAvailable = mergeChildCoinsAvailable(coinNodeLeft, coinNodeRight);
        vector<pair<int,int>> newCoinsNeeded = mergeChildCoinsNeeded(coinNodeLeft, coinNodeRight);

        if(root->val == 0){
            newCoinsNeeded.push_back(make_pair(root->val,0));
        }else if(root->val>1){
            newCoinsAvailable.push_back(make_pair(root->val,0));
        }

        sort(newCoinsAvailable.begin(),newCoinsAvailable.end(),coinComparator);
        sort(newCoinsNeeded.begin(),newCoinsNeeded.end(),coinComparator);

        int j=newCoinsNeeded.size()-1;
        vector<pair<int,int>>::iterator newCoinsAvailableIt = newCoinsAvailable.begin();
        int c;
        while(newCoinsAvailableIt!=newCoinsAvailable.end() && j>=0){
            c=newCoinsAvailableIt->first - 1;
            while(j>=0 && c>0){
           //     cout<<newCoinsAvailableIt->second<<" "<<newCoinsNeeded[j].second<<"\n";
                ans=ans+(newCoinsAvailableIt->second)+(newCoinsNeeded[j].second);
                newCoinsNeeded[j].second=-1;
                c--;
                j--;
            }
            if(c>0){
                newCoinsAvailable[0].first=c+1;
            }else{
                newCoinsAvailable.erase(newCoinsAvailableIt);
                newCoinsAvailableIt = newCoinsAvailable.begin();
            }
        }
        vector<pair<int,int>> newCoinsNeeded2;
        for(int i=0;i<newCoinsNeeded.size();i++){
            if(newCoinsNeeded[i].second!=-1){
                newCoinsNeeded2.push_back(newCoinsNeeded[i]);
            }
        }

        coinNode.coinsNeeded = newCoinsNeeded2;
        coinNode.coinsAvailable = newCoinsAvailable;
        return coinNode;
    }

public:
    int distributeCoins(TreeNode* root) {
        minDistributeCoins(root);
        return ans;
    }
};
