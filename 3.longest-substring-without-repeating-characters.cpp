/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_set<char> c;
        int max_num = 1, len = s.size(), j = 1;
        c.insert(s[0]);
        for(int i = 0 ; i < len ; i++){
            while (j < len && !c.count(s[j]))
            {
                c.insert(s[j]);
                j++;
            }
            if(c.size() > max_num){
                max_num = c.size();
            }
            c.erase(s[i]);
        }

        return max_num;
    }
};
// @lc code=end

