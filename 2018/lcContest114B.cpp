class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int,int> counter;
        map<int,int>::iterator counterIt;

        map<int,int> taken;
        map<int,int>::iterator takenIt;

        sort(A.begin(),A.end());
        for(int i=0;i<A.size();i++){
            counterIt = counter.find(A[i]);
            int ctr=0;
            if(counterIt != counter.end()){
                ctr=counterIt->second;
                counter.erase(counterIt);
            }
            ctr++;
            counter.insert(make_pair(A[i],ctr));
        }
        int zero=0;
        for(int i=0;i<A.size();i++){
            if(A[i]==0){
                zero++;
            }else{
                takenIt = taken.find(A[i]);
                if(takenIt!=taken.end()){
                    int ctr=takenIt->second;
                    ctr--;
                    taken.erase(takenIt);
                    if(ctr>0)
                    taken.insert(make_pair(A[i],ctr));
                }else{
                    int val;
                    if(A[i]<0){
                        val=A[i]/2;
                    }else if(A[i]>0){
                        val=A[i]*2;
                    }

                    counterIt = counter.find(val);
                    takenIt = taken.find(val);
                    int ctr=0;
                    if(takenIt!=taken.end()){
                        ctr=takenIt->second;
                    }
                    if(counterIt != counter.end() && counterIt->second - ctr > 0){
                        ctr++;
                        if(takenIt!=taken.end()){
                            taken.erase(takenIt);
                        }
                        taken.insert(make_pair(val,ctr));
                    }else{
                        return false;
                    }
                }
            }
        }
        return zero%2==0;
    }
};
