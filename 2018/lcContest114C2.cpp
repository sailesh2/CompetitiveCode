class Solution {
private:


    int minDeletion(vector<string>& A){

        int len = A.size();
        int strSize=A[0].size();


        int delPos[1000]={0};
        int cnt;
        while(1){
            cnt=0;
            for(int i=0;i<len-1;i++){
                int start=0;
                for(int j=0;j<strSize;j++){
                    if(delPos[j]==0){
                        start=j;
                        break;
                    }
                }
                if(A[i][start]>=A[i+1][start]){
                    for(int j=start;j<strSize;j++){
                        if(delPos[j]==1)
                            continue;
                        if(A[i][j]<A[i+1][j]){
                            break;
                        }else if(A[i][j]==A[i+1][j]){

                        }else{
                            delPos[j]=1;
                            cnt=1;
                        }
                    }
                }
            }
            if(cnt==0)
                break;
        }

        int ctr=0;
        for(int i=0;i<strSize;i++){
            if(delPos[i]==1)
                ctr++;
        }
        return ctr;
    }
public:
    int minDeletionSize(vector<string>& A) {
        return minDeletion(A);
    }
};
