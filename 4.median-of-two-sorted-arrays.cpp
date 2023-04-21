/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res = 0;
        int amount = nums1.size() + nums2.size();
        if(amount % 2 == 0)
        {
            res = findksmallest(nums1, nums2, amount/2 , 0, 0);
            res += findksmallest(nums1, nums2, amount/2 + 1 , 0, 0);
            res *= 0.5;
        }
        else
        {
            res = findksmallest(nums1, nums2, amount/2 + 1, 0, 0);
        }
        return res;
       
        
        
    }

    double findksmallest(vector<int>& nums1, vector<int>& nums2, int k, int left1, int left2){
        if(left1 == nums1.size()) return nums2[k + left2 - 1];
        if(left2 == nums2.size()) return nums1[k + left1 - 1];
        if (k == 1) return min(nums1[left1], nums2[left2]);
        int temp = k / 2 - 1;
        if (left1 + temp > nums1.size() - 1)
        {
            if(nums1[nums1.size() - 1] > nums2[temp + left2])
            {
                double res = findksmallest(nums1, nums2, k - k / 2, left1, left2 + k/2);
                return res;
            }
            else
            {
                double res = findksmallest(nums1, nums2, k - (nums1.size() - left1), nums1.size(), left2);
                return res;
            }
        }
        if(left2 + temp > nums2.size() - 1)
        {
            if(nums2[nums2.size() - 1] > nums1[temp + left1])
            {
                double res = findksmallest(nums1, nums2, k - k / 2, left1 + k/2, left2);
                return res;
            }
            else
            {
                double res = findksmallest(nums1, nums2, k - (nums2.size() - left2), left2, nums2.size());
                return res;
            }

        }
        if (nums1[temp + left1] > nums2[temp + left2])
        {
            double res = findksmallest(nums1, nums2, k - k / 2, left1 , left2 + k/2);
            return res;
        }
        else
        {
            double res = findksmallest(nums1, nums2, k - k / 2, left1 + k/2, left2 );
            return res;
        }
        
        return 0;
        

    }




};
// @lc code=end

