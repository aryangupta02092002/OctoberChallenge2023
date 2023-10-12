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
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low = 0, high = mountainArr.length()-1;
        int mid = low + (high-low)/2;

        while(low < high){
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                low = mid+1;
            }
            else{
                high = mid;
            }
            mid = low + (high-low)/2;
        }

        int peak = mid;
        int left = -1, right = -1;

        low = 0;
        high = peak;
        mid = low + (high-low)/2;

        while(low <= high){
            int middle = mountainArr.get(mid);
            if(middle == target){
                left = mid;
            }
            if(middle < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            mid = low + (high-low)/2;
        }

        low = peak;
        high = mountainArr.length()-1;
        mid = low + (high-low)/2;

        while(low <= high){
            int middle = mountainArr.get(mid);
            if(middle == target){
                right = mid;
            }
            if(middle > target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            mid = low + (high-low)/2;
        }

        if(left == right){
            return left;
        }
        else if(left != -1){
            return left;
        }
        else{
            return right;
        }
    }
};
