class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> u;
        int pairs = 0;
        for(int i=0; i<nums.size(); i++){
            if(u[nums[i]] > 0){
                pairs += u[nums[i]];
            }
            u[nums[i]]++;
        }
        return pairs;
    }
};
