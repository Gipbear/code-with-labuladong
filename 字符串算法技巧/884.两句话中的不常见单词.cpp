#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
 */

// @lc code=start
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // 学会字符空格直接分割
        vector<string> res;
        unordered_map<string, int> s_map;
        istringstream str1(s1), str2(s2);
        string out;
        while(str1 >> out){
            s_map[out]++;
        }
        while(str2 >> out){
            s_map[out]++;
        }
        for(auto t:s_map){
            if(t.second == 1)
                res.push_back(t.first);
        }
        return res;
    }
};
// @lc code=end

