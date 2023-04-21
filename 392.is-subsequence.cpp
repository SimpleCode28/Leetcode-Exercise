/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0 && t.size() == 0) return true;
        int k = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if(k == s.size())
            {
                return true;
            }
            if(t[i] == s[k])
            {
                k++;
            }
        }
        if(k == s.size())
        {
            return true;
        }
        return false;
        
    }
};
// @lc code=end

