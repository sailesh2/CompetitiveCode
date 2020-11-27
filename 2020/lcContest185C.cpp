class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int frogNo=0;
        vector<int> stkR;
        vector<int> stkO;
        vector<int> stkA;
        vector<int> stkK;
        int maxi=0;

        for(int i=0;i<croakOfFrogs.length();i++){
            char l = croakOfFrogs[i];

            if(l=='c'){
                frogNo++;
                maxi=max(maxi,frogNo);
                stkR.push_back(frogNo);
            }
            else if(l=='r'){
                if(stkR.size()==0){
                    return -1;
                }

                stkO.push_back(stkR[stkR.size()-1]);
                stkR.pop_back();
            }
            else if(l=='o'){
                if(stkO.size()==0){
                    return -1;
                }

                stkA.push_back(stkO[stkO.size()-1]);
                stkO.pop_back();

            }
            else if(l=='a'){
                if(stkA.size()==0){
                    return -1;
                }

                stkK.push_back(stkA[stkA.size()-1]);
                stkA.pop_back();
            }
            else{
                if(stkK.size()==0){
                    return -1;
                }

                stkK.pop_back();
                frogNo--;
            }
        }

        if(frogNo>0 || stkR.size()>0 || stkO.size()>0 || stkA.size()>0 || stkK.size()>0)
            return -1;
        return maxi;
    }
};
