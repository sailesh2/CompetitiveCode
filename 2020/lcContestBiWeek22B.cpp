class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int seats[n][10];
        for(int i=0;i<n;i++){
            for(int j=0;j<10;j++){
                seats[i][j]=0;
            }
        }
        for(int i=0;i<reservedSeats.size();i++){
            seats[reservedSeats[i][0]-1][reservedSeats[i][1]-1]=1;
        }
        int ctr=0;
        for(int i=0;i<n;i++){
            if(seats[i][1]==0 && seats[i][2]==0 && seats[i][3]==0 && seats[i][4]==0){
                seats[i][1]=1;
                seats[i][2]=1;
                seats[i][3]=1;
                seats[i][4]=1;
                ctr++;
            }

            if(seats[i][5]==0 && seats[i][6]==0 && seats[i][7]==0 && seats[i][8]==0){
                seats[i][5]=1;
                seats[i][6]=1;
                seats[i][7]=1;
                seats[i][8]=1;
                ctr++;
            }
        }

        for(int i=0;i<n;i++){
            if(seats[i][3]==0 && seats[i][4]==0 && seats[i][5]==0 && seats[i][6]==0){

                ctr++;
            }
        }

        return ctr;
    }
};
