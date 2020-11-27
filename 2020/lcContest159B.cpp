class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> folderSet;
        for(int i=0;i<folder.size();i++){
            folderSet.insert(folder[i]);
        }

        vector<string> ans;

        for(int i=0;i<folder.size();i++){
            string f="";
            int cnt=0;
            for(int j=0;j<folder[i].length()-1;j++){
                f.push_back(folder[i][j]);
                if(j+1<folder[i].length()-1 && folder[i][j+1]=='/'){
                if(folderSet.count(f)>0){
                    cnt=1;
                    break;
                }
                }
            }
            if(cnt==0){
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};
