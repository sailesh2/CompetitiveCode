class Solution {
private:
    double getDegree(double minHand){
        return 360*(minHand/60);
    }

    double getMinuteHand(int hour, int minutes){
        int minH = (hour%12)*5;
        return minH+5*((double)minutes/60);
    }
public:
    double angleClock(int hour, int minutes) {
        double minDeg = getDegree(minutes);
        double hourDeg = getDegree(getMinuteHand(hour,minutes));

        double diff = abs(minDeg - hourDeg);
        return min(diff, abs(360-diff));
    }
};
