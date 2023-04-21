/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        if(nums[0] > 0) return {};
        vector<vector<int>> v;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] > 0) return v;
            int j = i + 1, k = nums.size() - 1, target = -nums[i];
            while (j < k)
            {
                if(nums[j] + nums[k] > target)
                {
                    k--;
                    while ((k > j) && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                    continue;
                }
                if(nums[j] + nums[k] == target)
                {
                    v.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while ((k > j) && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                    while ((k > j) && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    continue;
                }
                j++; 
            }
            i++;
            while (i < nums.size() && nums[i] == nums[i - 1])
            {
                i++;
            }
            
        }
        return v;
    }
};
// @lc code=end

