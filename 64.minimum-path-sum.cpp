/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int* dp = new int[grid[0].size()];
        memset(dp, 0, sizeof(int) * grid[0].size());
        dp[0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); i++)
        {
            dp[i] = grid[0][i] + dp[i - 1];
        }
        for (int i = 1 ; i < grid.size() ; i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int left = 200, right = 200;
                left = dp[j];
                if(j - 1 > -1)
                {
                    right = dp[j - 1];
                }
                dp[j] = min(left, right) + grid[i][j];
            }
            
        }
        return dp[grid[0].size() - 1];
        // int result = dp[grid[0].size() - 1];
        // delete []dp;
        // return result; 
    }
    
};
// @lc code=end

