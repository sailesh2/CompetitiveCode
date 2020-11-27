class Solution {
private:

    int getMinPoint(vector<int> t, int* has){

        int mini=100000000;
        int save=0;
        for(int i=0;i<t.size();i++){
            if(has[i]==0){
                if(t[i]<mini){
                    mini=t[i];
                    save=i;
                }
            }
        }

        return save;
    }

    int minTraingleScore(vector<int> t){
        if(t.size()<3){
            return 0;
        }
        int has[55]={0};

        int index = getMinPoint(t,has);
        has[index]=1;

        int index2 = getMinPoint(t,has);
        has[index2]=1;

        int index3 = getMinPoint(t,has);
        has[index3]=1;

        vector<int> indices;
        indices.push_back(index);
        indices.push_back(index2);
        indices.push_back(index3);

        sort(indices.begin(),indices.end());

        vector<int> triangle;
        vector<int> triangle2;
        vector<int> triangle3;

        for(int i=0;i<=indices[0];i++){
            triangle.push_back(t[i]);
        }
        for(int i=indices[2];i<t.size();i++){
            triangle.push_back(t[i]);
        }

        for(int i=indices[0];i<=indices[1];i++){
            triangle1.push_back(t[i]);
        }

        for(int i=indices[1];i<=indices[2];i++){
            triangle2.push_back(t[i]);
        }

        int currentTriangleScore = t[index]*t[index2]*t[index3];

        return minTraingleScore(triangle) + minTraingleScore(triangle1) + minTraingleScore(triangle2) + currentTriangleScore;
    }
public:
    int minScoreTriangulation(vector<int>& A) {
        return minTraingleScore(A);
    }
};
