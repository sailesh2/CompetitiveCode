#include<bits/stdc++.h>

using namespace std;


class Solution {
int has[60][60]={0};
private:
void fillImage(vector<vector<int> > &im, int i, int j, int o,int c){
    if(i<0 || i>=im.size() || j<0 || j>=im[i].size())
        return;
    if(has[i][j]==1)
        return;
    if(im[i][j]==o){
        im[i][j]=c;
        has[i][j]=1;
        fillImage(i+1,j+1);
        fillImage(i+1,j-1);
        fillImage(i-1,j+1);
        fillImage(i-1,j-1);
    }
};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        fillImage(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
};
