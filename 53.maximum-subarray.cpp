/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp = nums[0];
        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            temp = temp < 0 ? nums[i] : nums[i] + temp;
            if(temp > max_sum){
                max_sum = temp;
            }
        }
        
        return max_sum;
    }
};
// @lc code=end

