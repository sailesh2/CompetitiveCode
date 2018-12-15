class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA=0;
        int i=0,j=height.size()-1,maxi=0;
        while(i<=j){
            if(height[i]>maxi){
                maxi=height[i];
                while(j>=i){
                    if(height[j]>=height[i]){
                        maxA=max(maxA,height[i]*(j-i));
                        break;
                    }
                    j--;
                }
            }
            i++;
        }

        i=0;
        j=height.size()-1;
        maxi=0;
        while(i<=j){
            if(height[j]>maxi){
                maxi=height[j];
                while(i<=j){
                    if(height[i]>=height[j]){
                        maxA=max(maxA,height[j]*(j-i));
                        break;
                    }
                    i++;
                }
            }
            j--;
        }
        return maxA;
    }
};
