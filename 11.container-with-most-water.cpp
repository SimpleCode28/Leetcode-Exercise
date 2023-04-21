/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int i = 0, j = height.size() - 1;
        while( i < j )
        {
            maxWater = max(maxWater, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
            {
                i++;
            }else{
                j--;
            }
            
            
        }
        return maxWater;
    }
};
// @lc code=end

