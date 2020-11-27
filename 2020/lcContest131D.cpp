class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int t=0;
        int has[200]={0};
        int maxi=0;
        int save=-1;
        int ctr=0;
        while(t<T){
            save=-1;
            for(int i=0;i<clips.size();i++){
                if(has[i]==0 && clips[i][0]<=t){
                    if(clips[i][1]>maxi){
                        maxi=clips[i][1];
                        save=i;
                    }
                }
            }
            if(save==-1)
                break;
            ctr++;
            t=maxi;
        }
        if(save==-1)
            return -1;
        return ctr;
    }
};
