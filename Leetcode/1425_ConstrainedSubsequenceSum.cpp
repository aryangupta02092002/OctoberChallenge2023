class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        maxHeap.push({nums[0], 0});
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            while (i - maxHeap.top().second > k) { 
                maxHeap.pop(); 
            }

            int curr = max(0, maxHeap.top().first) + nums[i];
            ans = max(ans, curr);
            maxHeap.push({curr, i});
        }

        return ans;
    }
};
