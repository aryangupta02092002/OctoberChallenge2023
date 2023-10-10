Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/?envType=daily-question&envId=2023-10-10
class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int left = 0;
        int mxCount = 1;
        int currCount = 1;

        for(int right=1; right<sz; right++){
            if(nums[right] == nums[right-1]){
                continue;
            }
            while(nums[right] - nums[left] > sz-1){
                if(left < sz && nums[left+1] == nums[left]){
                    currCount++;
                }
                left++;
                currCount--;
            }
            currCount++;
            mxCount = max(mxCount, currCount);
        }
        int minOps = sz - mxCount;
        return minOps;
    }
};
