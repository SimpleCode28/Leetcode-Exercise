/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
/**思路：**/
class Solution {
public:
    string longestPalindrome(string s) {
        for (int i = 0; i < s.length() + 1; i = i + 2)
        {
            s.insert(i, 1,'*');
        }
        string str = s.substr(0, 1); //从下标0开始截取，截取长度为1
        int maxlen = 3, startpos = 0;
        for(int i = 0 ; i < s.length() ; i++)
        {
            int templen = 1;
            for (int start = i - 1, end = i + 1; start > -1 && end < s.length(); start--, end++)
            {
                if(s[start] == s[end])
                {
                    templen += 2;
                    if(templen >= maxlen)
                    {
                        maxlen = templen;
                        startpos = start;
                    }
                }
                else
                {
                    break;
                }
                
            }
            
        }
        str = s.substr(startpos, maxlen);
        str.erase(std::remove(str.begin(), str.end(), '*'), str.end());
        return str;
        
    }
};
// @lc code=end

