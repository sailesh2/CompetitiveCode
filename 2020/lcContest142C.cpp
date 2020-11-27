/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
private:
    long long int binSearPivotWithMiddle(long long int low, long long int high, MountainArray arr){
        if(low==high){
            return low;
        }

        long long int mid = (low+high)/2;

        if(arr.get(mid)>arr.get(mid-1) && arr.get(mid)>arr.get(mid+1))
            return mid;

        if(arr.get(mid)>arr.get(mid+1)){
            return binSearPivotWithMiddle(low,mid,arr);
        }else{
            return binSearPivotWithMiddle(mid,high,arr);
        }
    }

    long long int binSearWithMiddle(long long int low, long long int high, long long int sear, MountainArray arr){
        if(low==high){
            return sear==arr.get(low) ? low : -1;
        }

        if(low==high-1){
            if(sear == arr.get(low))
                return low;
            if(sear == arr.get(high))
                return high;
            return -1;
        }

        long long int mid = (low+high)/2;

        if(arr.get(mid)==sear)
            return mid;

        if(sear<arr.get(mid)){
            return binSearWithMiddle(low,mid,sear,arr);
        }else{
            return binSearWithMiddle(mid,high,sear,arr);
        }
    }

    long long int binSearWithMiddleBack(long long int low, long long int high, long long int sear, MountainArray arr){
        if(low==high){
            return sear==arr.get(low) ? low : -1;
        }
        if(low==high-1){
            if(sear == arr.get(low))
                return low;
            if(sear == arr.get(high))
                return high;
            return -1;
        }

        long long int mid = (low+high)/2;

        if(arr.get(mid)==sear)
            return mid;

        if(sear>arr.get(mid)){
            return binSearWithMiddleBack(low,mid,sear,arr);
        }else{
            return binSearWithMiddleBack(mid,high,sear,arr);
        }
    }

    int getPivot(MountainArray &mountainArr){
        int pivot = binSearPivotWithMiddle(0,mountainArr.length()-1,mountainArr);
        return pivot;
    }

    int findTarget(int pivot, int target, MountainArray &mountainArr){

        int index = binSearWithMiddle(0,pivot,target,mountainArr);
        if(index>=0 && mountainArr.get(index)==target)
            return index;
        index = binSearWithMiddleBack(pivot,mountainArr.length()-1,target,mountainArr);
        if(index>=0 && mountainArr.get(index)==target)
            return index;
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        return findTarget(getPivot(mountainArr), target, mountainArr);
    }
};
