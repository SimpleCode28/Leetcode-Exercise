/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(target == nums[0])  return 0;
            else return -1;
        }
        return searchtar(nums, target, 0, nums.size() - 1);
    }

    int searchtar(vector<int>& nums, int target, int start, int end){
        if(end < start) return -1;
        if(end - start == 1){
            if(nums[end] == target) return end;
        }
        if(nums[end] < nums[start]){
            int middle = (end + start)/2;
            if(nums[middle] == target) return middle;
            int r1 = searchtar(nums, target, start, middle - 1);
            int r2 = searchtar(nums, target, middle + 1, end);
            if(r1 > r2){return r1;}
            else{return r2;}

        }else{
            if(target > nums[end] || target < nums[start]) return -1;
            int middle = (end + start) /2;
            if(nums[middle] == target) return middle;
            if (nums[middle] > target)
            {
                return searchtar(nums, target, start, middle - 1);
            }else{
                return searchtar(nums, target, middle + 1, end);
            } 
        }
        return -1;
    }
};
// @lc code=end

