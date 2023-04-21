/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
/**思路：只和前两个数字有关
 * 遇到数字0的时候需要判断是否可以发生映射**/
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        if(s.length() == 1) return 1;
        int pre = 1;
        if(s[0] == '1' || s[0] == '2'){
            if(s[1] == '0') {int post = 1;}
            else{int post = 2;}
        }
        else{
            if(s[1] == '0'){
               return 0;
            }
            int post = 1;
        }
        for (int i = 2; i < s.size(); i++)
        {
            //判断读到0时
            if(s[i] == '0'){
                if(s[i - 1] == '1' || s[i - 1] == '2') 
                {
                    
                    continue;
                }
                else {return 0;}
            }

        }
        
        
        
    }
};
// @lc code=end

