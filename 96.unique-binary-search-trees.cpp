/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start

class Solution {
public:
    
    /**递归**/
    // int numTrees(int n) {
    //     if(n == 1 || n == 0) return 1;
    //     if(n == 2) return 2;
    //     int sum = 0;
    //     for(int i = 0 , left = 0, right = n - 1; i < n ; i++, left++, right--){
    //         sum += numTrees(left) * numTrees(right);
    //     }
    //     return sum;
    // }
    
    /**动态规划**/
    int numTrees(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int dp[n + 1];
        memset(dp, 0, sizeof(dp)); //初始化为0
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n ; i++){
            for(int left = 0 , right = i - 1 ; right >= 0;left++, right--){
                dp[i] += dp[left]*dp[right];
            }
            
        }
        return dp[n];
    }
    
};
// @lc code=end

