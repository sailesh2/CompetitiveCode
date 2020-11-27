class Solution {
private:
    int longest(vector<int> hours){

        int cuml[hours.size()];
        int s=0;
        int maxBack[hours.size()];
        for(int i=0;i<hours.size();i++){
            if(hours[i]>8)
                s++;
            else
                s--;
            cuml[i]=s;
        }
        int maxi=-1000000;
        for(int i=hours.size()-1;i>=0;i--){
            maxi=max(cuml[i],maxi);
            maxBack[i]=maxi;
        }


        int start=0;
        int prev=0;
        int end=start;
        maxi=0;
        for(int i=end;i<hours.size();i++){
            if(maxBack[i]-prev<=0)
                break;

            end=i;
            maxi=max(maxi,end-start+1);
        }

        while(start<hours.size()){
            prev=prev+(hours[start]>8?1:-1);
            start++;
            if(start>end)
                end=start;
            for(int i=end;i<hours.size();i++){
                if(maxBack[i]-prev<=0)
                        break;
                end=i;
                maxi=max(maxi,end-start+1);
            }

        }
        return maxi;
    }

public:
    int longestWPI(vector<int>& hours) {
        return longest(hours);

    }
};
