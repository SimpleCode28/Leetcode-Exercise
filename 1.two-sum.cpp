/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     if(nums.size() == 2) return {0,1};
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         int temp = target - nums[i];
    //         for (int j = i + 1; j < nums.size() ; j++)
    //         {
    //             if(nums[j] == temp)
    //                 return {i, j};
    //         }
            
    //     }
    //     return {0,1};    
    // }

    vector<int> twoSum(vector<int>& nums, int target){
        // if(nums.size() == 2) return {0, 1};
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = hashtable.find(target-nums[i]);
            if ((it != hashtable.end()))
            {
                return {i, it->second};
            }
            hashtable[nums[i]]=i;
            
        }

        return {0, 1};
        
    }
};
// @lc code=end

