/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int pre_1 = 1, pre_2 = 2, result = 0;
        for(int i = 2 ; i < n ; i++)
        {
            pre = pre_1 + pre_2;
            pre_1 = pre_2;
            pre_2 = result;
        }

        return result;
        
    }
};
// @lc code=end

