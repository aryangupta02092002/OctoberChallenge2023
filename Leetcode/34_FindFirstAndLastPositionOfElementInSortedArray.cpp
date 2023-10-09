class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int start = -1, end = -1;
        int sz = nums.size();

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                int tmp = mid;
                while(mid > 0 && nums[mid-1] == target){
                    mid--;
                }
                start = mid;

                while(tmp < sz-1 && nums[tmp+1] == target){
                    tmp++;
                }
                end = tmp;

                return {start, end};
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return {start, end};
    }
};
