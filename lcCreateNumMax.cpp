class Solution {
private:
    int greaterThan(vector<int>& nums1, vector<int>& nums2, int start1, int end1, int start2, int end2){
        int max1=-1,save1=-1;
        for(int i=start1;i<=end1;i++){
            if(nums1[i]>max1){
                max1=nums1[i];
                save1=i;
            }
        }

        int max2=-1,save2=-1;
        for(int i=start2;i<=end2;i++){
            if(nums2[i]>max2){
                max2=nums2[i];
                save2=i;
            }
        }
        return max1>max2 ? 1 : max2>max1 ? 2 : save1>save2 ? 1 : 2;
    }
    pair<int,int> findMax(vector<int>& nums1, vector<int>& nums2, int start1, int end1, int start2, int end2, int k){
        int max1=-1,save1=-1;
        for(int i=start1;i<=end1;i++){
            if(nums1[i]>max1){
                max1=nums1[i];
                save1=i;
            }
        }

        int max2=-1,save2=-1;
        for(int i=start2;i<=end2;i++){
            if(nums2[i]>max2){
                max2=nums2[i];
                save2=i;
            }
        }

        if(max1>max2){
            if(end1-save1+1 + end2-start2+1 >=k){
                return make_pair(1,save1);
            }else{
                return findMax(nums1,nums2,start1,save1-1,start2,end2,k-(end1-save1+1));
            }
        }else if(max2>max1){
            if(end2-save2+1 + end1-start1+1 >=k){
                return make_pair(2,save2);
            }else{
                return findMax(nums1,nums2,start1,end1,start2,save2-1,k-(end2-save2+1));
            }
        }else{
            int loc = greaterThan(nums1,num2.start1,end1,start2,end2);
            if(loc==1){
                if(end1-save1+1 + end2-start2+1 >=k){
                    return make_pair(1,save1);
                }else{
                    return findMax(nums1,nums2,start1,save1-1,start2,end2,k-(end1-save1+1));
                }
            }else{
                if(end2-save2+1 + end1-start1+1 >=k){
                    return make_pair(2,save2);
                }else{
                    return findMax(nums1,nums2,start1,end1,start2,save2-1,k-(end2-save2+1));
                }
            }
        }
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        int p1=0,p2=0;
        while(k>0){
            pair<int,int> pos = findMax(nums1,nums2,p1,nums1.size()-1,p2,nums2.size()-1,k);
            if(pos.first==1){
                p1=pos.second;
                ans.push_back(nums1[p1]);
                p1++;
            }else{
                p2=pos.second;
                ans.push_back(nums2[p2]);
                p2++;
            }
            k--;
        }
        return ans;
    }
};
