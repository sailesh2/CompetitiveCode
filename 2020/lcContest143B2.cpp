class Solution {
private:

    vector<int> path;
    map<int,int> pathMap;
    map<int,int>::iterator pathMapIt;


    void createZigZagTree(int label){
        path.push_back(label);
        while(label>1){
            label=label/2;
            if(label==1){
                path.push_back(label);
                return;
            }
            int l=(int)floor(log2(label));
            int h=l+1;
            int lv=pow(2,l);
            int hv=pow(2,h)-1;
            label=lv+hv-label;
            path.push_back(label);
        }
    }


public:
    vector<int> pathInZigZagTree(int label) {
        createZigZagTree(label);
        vector<int> revPath;
        for(int i=path.size()-1;i>=0;i--)
            revPath.push_back(path[i]);
        return revPath;
    }
};
