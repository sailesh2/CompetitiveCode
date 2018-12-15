class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n=A.size();
        if(n==0 || n==1)
            return 0;

        vector<int> priorityQueue;
        int score=0,saveZ=-1;
        int maxScore=0,saveK=0;
        for(int i=0;i<A.size();i++){
            if(A[i]<=i)
                score++;
            if(A[i]==0){
                saveZ=(1+i-A[i]+n)%n;
            }
            priorityQueue.push_back((i-A[i]+n)%n);
        }
        maxScore=score;
        int rear=0;
        sort(priorityQueue.begin(),priorityQueue.end());
        for(int k=1;k<n;k++){

            while(rear<priorityQueue.size() && k>priorityQueue[rear]){
                score--;
                rear++;
            }
            if(k!=saveZ){
                score++;
            }
            if(score>maxScore){
                maxScore=score;
                saveK=k;
            }
        }
        return saveK;
    }
};
