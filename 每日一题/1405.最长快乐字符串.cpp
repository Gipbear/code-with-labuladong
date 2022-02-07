#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=1405 lang=cpp
 *
 * [1405] 最长快乐字符串
 */

// @lc code=start
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        vector<pair<int, char>> arr{{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while(true){
            // 优先使用个数多的字母
            sort(rbegin(arr), rend(arr));
            // 已经快乐的长度
            int pre_sz = res.size();
            for(auto &e : arr){
                // 当前字母 用完 或 刚插入过两次, 则跳过
                if(e.first == 0 || res.size() >= 2 && e.second == res.back() && e.second == res[res.size()-2])
                    continue;
                // 插入该字母
                res += e.second;
                --e.first;
                break;
            }
            // 字母长度不变
            if(pre_sz == res.size())
                break;
        }
        return res;
    }
};
// @lc code=end

