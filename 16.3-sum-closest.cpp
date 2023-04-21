/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        if(nums.size() == 3) return res;
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1, k = nums.size() - 1, goal = target - nums[i];
            short signal = 0;
            while ( j < k)
            {
                if (nums[j] + nums[k] > goal)
                {
                    signal = 1;
                    int res1 = nums[i] + nums[j] + nums[k];
                    if (abs(target - res1) < abs(target - res))
                    {
                        res = res1;
                    }
                    if(signal == -1) break;
                    k--;
                    while(j < k && nums[k] == nums[k + 1]){
                        k--;
                    }
                }
                else if(nums[j] + nums[k] < goal)
                {
                    signal = -1;
                    int res1 = nums[i] + nums[j] + nums[k];
                    if (abs(target - res1) < abs(target - res))
                    {
                        res = res1;
                    }
                    if(signal == 1) break;
                    j++;
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                }else{
                    return target;
                }    
            }
        }
        return res;
        
    }
};
// @lc code=end

