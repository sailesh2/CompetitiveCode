class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int totSum=0,d=0;

        for(int i=0;i<distance.size();i++){
            totSum=totSum+distance[i];
        }
        int mini=min(start,destination);
        int maxi=max(start,destination);
        for(int i=mini;i<maxi;i++){
            d=d+distance[i];
        }


        return min(d, totSum-d);
    }
};
