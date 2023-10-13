class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int mn1 = 0, mn2 = 0;

        for(int i=0; i<cost.size(); i++){
            int mn0 = cost[i] + min(mn1, mn2);
            mn2 = mn1;
            mn1 = mn0;
        }
        return min(mn1, mn2);
    }
};
