class Solution {
private:
    void swap(vector<int>& A, int dest){
        vector<int> temp;
        for(int i=0;i<=dest;i++){
            temp.push_back(A[i]);
        }
        for(int i=0;i<=dest;i++){
            A[i]=temp[temp.size()-i-1];
        }
    }
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> order;
        int sortInd = A.size();
        while(sortInd>0){
            int cnt=-1;
            for(int i=0;i<sortInd;i++){
                if(A[i]==sortInd){
                    cnt=i;
                    break;
                }
            }
            if(cnt+1==sortInd){
                sortInd--;
            }else{
                if(cnt!=0){
                    swap(A,cnt);
                    order.push_back(cnt+1);
                }
                swap(A,sortInd-1);
                order.push_back(sortInd);
            }
        }
        return order;
    }
};
