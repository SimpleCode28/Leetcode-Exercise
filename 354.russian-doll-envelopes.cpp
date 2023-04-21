/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 1) return 1;
        sort(envelopes.begin(),envelopes.end(), cmp);
        vector<int> temp;
        temp.emplace_back(0);
        temp.emplace_back(envelopes[0][1]);
        for(int i = 1 ; i<envelopes.size() ; i++){
            if(envelopes[i][1] > temp[temp.size() - 1]){
                temp.emplace_back(envelopes[i][1]);
            }else if(envelopes[i][1] == temp[temp.size() - 1]){
                continue;
            }else{
                int left = 1, right = temp.size() - 1, pos = 0;
                while (left <= right)
                {
                    int middle = (left + right) / 2;
                    if(temp[middle] < envelopes[i][1]){
                        pos = middle;
                        left = middle + 1;
                    }else{
                        right = middle - 1;
                    }
                }
                temp[pos + 1] = envelopes[i][1];
            }
        }
        return temp.size() - 1;
    }

    static bool cmp(const vector<int>& v1, const vector<int>& v2){
        if (v1[0] == v2[0]) return v1[1]>v2[1];
        return v1[0] < v2[0];
    }


};
// @lc code=end

