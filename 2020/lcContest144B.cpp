class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int seats[20005]={0};

        for(int i=0;i<bookings.size();i++){
            seats[bookings[i][0]]=seats[bookings[i][0]]+bookings[i][2];
            seats[bookings[i][1]+1]=seats[bookings[i][1]+1]-bookings[i][2];
        }

        vector<int> seatPlanes;
        int totSeats=0;
        for(int i=1;i<=n;i++){
            totSeats=totSeats+seats[i];
            seatPlanes.push_back(totSeats);
        }
        return seatPlanes;
    }
};
