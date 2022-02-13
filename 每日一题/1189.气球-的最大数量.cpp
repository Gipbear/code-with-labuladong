#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 */

// @lc code=start
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> words;
        for(char ch : text)
            words[ch]++;
        int res = min(words['a'], min(words['b'], words['n']));
        res = min(int(min(words['l'], words['o'])/2), res);
        return res;
    }
};
// @lc code=end

