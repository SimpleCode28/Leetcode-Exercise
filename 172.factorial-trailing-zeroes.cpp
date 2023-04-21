/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int k = 0;
        while ( n )
        {
            n = n / 5;
            k += n;
        }
        return k;
    }
};
// @lc code=end

