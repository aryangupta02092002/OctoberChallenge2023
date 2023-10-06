class Solution {
public:
    int integerBreak(int n) {
        int dp[60];
        dp[2] = 1;
        for(int i=3; i<=n; i++){
            int tmp = 1;
            for(int j=2; j<i; j++){
                tmp = max(max(dp[j], j) * (i-j), tmp);
            }
            dp[i] = tmp;
        }
        return dp[n];
    }
};
