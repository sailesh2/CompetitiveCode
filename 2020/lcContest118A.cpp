class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int i=0;
        int p;
        vector<int> pInts;
        set<int> present;

        if(x==1 && y==1){
            if(2<=bound)
                pInts.push_back(2);
            return pInts;
        }else if(x==1){
            while(1){
                p=pow(y,i)+1;
                if(p>bound)
                break;
                if(present.count(p)==0){
                    present.insert(p);
                    pInts.push_back(p);
                }
                i++;
            }
            return pInts;
        }else if(y==1){
            while(1){
                p=pow(x,i)+1;
                if(p>bound)
                break;
                if(present.count(p)==0){
                    present.insert(p);
                    pInts.push_back(p);
                }
                i++;
            }
            return pInts;
        }else{

        while(1){
            int j=0;
            p=pow(x,i)+1;
            if(p>bound)
                break;
            while(p<=bound){
                p=pow(x,i) + pow(y,j);

                if(p>bound)
                    break;
                if(present.count(p)==0){
                    present.insert(p);
                    pInts.push_back(p);
                }
                j++;
            }
            i++;
        }
        return pInts;
        }
    }
};
