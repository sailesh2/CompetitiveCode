class Solution {
private:
    int n;
    bool areCouple(int i, int j, vector<int> r){

        if(i<0 || i>=n || j<0 || j>=n)
            return false;

        if(r[i]%2==0){
            return r[i]+1==r[j];
        }else{
            return r[i]-1==r[j];
        }
    }
public:
    int minSwapsCouples(vector<int>& row) {
        n=row.size();
        vector<int> orig;
        for(int i=0;i<row.size();i++)
            orig.push_back(row[i]);
        int has[100];
        for(int i=0;i<100;i++)
            has[i]=-1;
        int pos[100];
        for(int i=0;i<row.size();i++){
            pos[row[i]]=i;
        }

        int swaps=0;

        int i=0;
        while(i<row.size()){
            int pt = row[i]%2==0?row[i]+1:row[i]-1;
            int pti=pos[pt];

            if(pti-1==i || pti+1==i){
                i++;
                continue;
            }
            if(areCouple(i+1,pti-1,row))
                pti--;
            else if(areCouple(i+1,pti+1,row))
                pti++;
            else{
            if(pti>0)
                pti--;
            else
                pti++;
            }

            swaps++;
            int temp=row[i];
            row[i]=row[pti];
            row[pti]=temp;

            pos[row[i]]=i;
            pos[row[pti]]=pti;
        }

//        for(int i=0;i<row.size();i++)
//            cout<<row[i]<<" ";
        /*int origPos[100];
        for(int i=0;i<orig.size();i++){
            origPos[orig[i]]=i;
        }

        for(int i=0;i<row.size();i++){
            if(orig[i]!=row[i]){
                if(has[i]==-1 && has[origPos[row[i]]]==-1)
                swaps++;
                has[i]=1;
                has[origPos[row[i]]]=1;
            }
        }*/
        return swaps;
    }
};
