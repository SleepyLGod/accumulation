class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;

        const int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, 0x3f3f3f3f));
        dp[0] = costs[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == k) continue;
                    
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + costs[i][j]);
                }
            }
        }
        
        return min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
    }
};
