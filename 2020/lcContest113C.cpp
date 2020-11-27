class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans;
        if(n==0)
            return ans;
        int arr[n];
        int j=0,ctr=0;
        int has[10005]={0};
        sort(deck.begin(),deck.end());
        arr[0]=deck[0];
        has[0]=1;
        for(int i=1;i<n;i++){
            ctr=0;

            while(1){
                if(has[j]==0){
                    ctr++;
                    if(ctr==2){
                        has[j]=1;
                        arr[j]=deck[i];
                        j=(j+1)%n;
                        break;
                    }
                }
                j=(j+1)%n;
            }
        }

        for(int i=0;i<n;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
