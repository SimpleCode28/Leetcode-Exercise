/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        vector<int> v = search(nums, target, 0, nums.size() - 1);
        return v;
    }

    vector<int> search(vector<int>& nums, int target, int start, int end){
        if (end < start)
        {
            return {-1, -1};
        }
        vector<int> v;
        int middle = (end + start)/2;
        if(target == nums[middle]){
            vector<int> r1 = search(nums, target, start, middle - 1);
            vector<int> r2 = search(nums, target, middle + 1, end);
            if(r1[1]!= -1){
                if(r1[0] != -1){
                    v.push_back(r1[0]);
                }else{
                    v.push_back(r1[1]);
                }
            }
            else
            {
                v.push_back(middle);
            }
            if(r2[0]!= -1){
                if(r2[1] != -1){
                    v.push_back(r2[1]);
                }else{
                    v.push_back(r2[0]);
                }
            }
            else
            {
                v.push_back(middle);
            }
            return v;
        }else if(target < nums[middle]){ 
            v = search(nums, target, start, middle -1);
        }else{
            v = search(nums, target, middle + 1, end);
        }
        return v;
    }
};
// @lc code=end

