/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int len = obstacleGrid[0].size();
        int* dp = new int[len];
        memset(dp, 0, sizeof(int) * len);
        if(obstacleGrid[0][0]) return 0;
        dp[0] = 1;
        for (int i = 1; i < len; i++)
        {
            if(dp[i - 1] && !obstacleGrid[0][i]){
                dp[i] = 1;
            }else{
                break;
            }
        }
        for (int i = 1; i < obstacleGrid.size(); i++)
        {
            for (int j = 0; j < len; j++)
            {
                if(obstacleGrid[i][j]){
                    dp[j] = 0;
                }else{
                    if(j - 1 > -1){
                        dp[j] = dp[j - 1] + dp[j];
                    }  
                }
            }
        }

        return dp[len - 1];
        
    }

  
};
// @lc code=end

