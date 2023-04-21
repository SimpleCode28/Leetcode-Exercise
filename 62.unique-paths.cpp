/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m > n){
            n = m + n;
            m = n - m;
            n = n - m;
        }
        int* dp = new int[m];
        fill_n(dp, m, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[j] += dp[j - 1];
            }
        }

        return dp[m - 1];  
    }
};
// @lc code=end

