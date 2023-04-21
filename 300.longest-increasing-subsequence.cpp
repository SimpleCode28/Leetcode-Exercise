/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.emplace_back(0);
        temp.emplace_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > temp[temp.size() - 1]){
                temp.emplace_back(nums[i]);
                
            }
            else if(nums[i] == temp[temp.size() - 1]){
                continue;
            }
            else{
                int start = 1, end = temp.size() - 1, pos = 0;
                while (start <= end)
                {
                    int middle = (start + end) / 2;
                    if(temp[middle] < nums[i]){
                        start = middle + 1;
                        pos = middle;
                    }else{
                        end = middle - 1;
                    }
                }
                temp.at(pos + 1) = nums[i];         
            }
        }
        
        return temp.size() - 1;
        
    }
};
// @lc code=end

