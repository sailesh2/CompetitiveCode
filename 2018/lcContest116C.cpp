class Solution {
private:
    double minArea=1000000000;
    vector<vector<int>> cords;

    double getLen(int a, int b, vector<int>& choosen){
        return (double)((choosen[a][1]-choosen[b][1])*(choosen[a][1]-choosen[b][1]) - (choosen[a][0]-choosen[b][0])*(choosen[a][0]-choosen[a][0]));
    }

    double getArea(int a, int b, int c, vector<int>& choosen){
        double len1 = getLen(a,b);
        double len2 = getLen(a,c);
        return len1*len2;
    }

    bool isPossibleRect(int a, int b, int c,int d, vector<int>& choosen){
        float slope1=(float)(choosen[a][1] - choosen[b][1])/(choosen[a][0] - choosen[b][0]);

        float slope2=(float)(choosen[c][1] - choosen[d][1])/(choosen[c][0] - choosen[d][0]);

        float slope3=(float)(choosen[a][1] - choosen[c][1])/(choosen[a][0] - choosen[c][0]);

        double len1 = getLen(a,b);
        double len2 = getLen(c,d);
        double len3 = getLen(a,c);
        double len4 = getLen(b,d);

        return slope1 == slope2 && slope1*slope3 == -1 && len1==len2 && len3==len4;
    }

    void findMinArea(vector<int>& choosen){
        if(isPossibleRect(0,1,2,3,choosen)){
            minArea = min(minArea, getArea(0,1,2,choosen));
        }
        if(isPossibleRect(0,2,1,3,choosen)){
            minArea = min(minArea, getArea(0,2,1,choosen));
        }
        if(isPossibleRect(0,3,1,2,choosen)){
            minArea = min(minArea, getArea(0,3,1,choosen));
        }
    }

    void chooseCoordinates(int start,vector<int>& choosen){
        if(choosen.size()==4){
            findMinArea(choosen);
            return;
        }
        for(int i=start;i<cords.size();i++){
            choosen.push_back(i);
            chooseCoordinates(i+1,choosen);
            choosen.pop_back();
        }
    }
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        chooseCoordinates(0,points);
        return minArea;
    }
};
