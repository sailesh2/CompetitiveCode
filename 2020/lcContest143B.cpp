class Solution {
private:

    vector<int> path;
    int pathMap[1000001];


    void createZigZagTree(int label){
        int ctr=1;
        vector<int> lnodes;
        vector<int> nextlnodes;
        lnodes.push_back(ctr);
        int cnt=1;
        while(ctr<label){

            if(cnt==0){
                for(int i=0;i<lnodes.size();i++){
                    ctr++;
                    nextlnodes.push_back(ctr);
                    ctr++;
                    nextlnodes.push_back(ctr);
                }
                lnodes.clear();
                for(int i=0;i<nextlnodes.size();i++){
                    lnodes.push_back(nextlnodes[i]);
                }
                nextlnodes.clear();

            }else{
                for(int i=lnodes.size()-1;i>=0;i--){

                    ctr++;
                    nextlnodes.push_back(ctr);
                    ctr++;
                    nextlnodes.push_back(ctr);
                }

                lnodes.clear();
                for(int i=nextlnodes.size()-1;i>=0;i--){
                    lnodes.push_back(nextlnodes[i]);
                }
                nextlnodes.clear();
            }
            cnt=1-cnt;
        }

    }

    void traverse(int label){

        path.push_back(label);
        if(label==1)
            return;
        traverse(pathMap[label]);
    }


public:
    vector<int> pathInZigZagTree(int label) {
        createZigZagTree(label);
        traverse(label);
        vector<int> revPath;
        for(int i=path.size()-1;i>=0;i--)
            revPath.push_back(path[i]);
        return revPath;
    }
};
