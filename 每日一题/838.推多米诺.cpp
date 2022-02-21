#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=838 lang=cpp
 *
 * [838] 推多米诺
 */

// @lc code=start
class Solution {
public:
    string pushDominoes(string dominoes) {
        // 增加虚拟结点，使得区间完整
        dominoes = "L" + dominoes + "R";
        int l = 0;
        string res = "";
        for (int r = 1; r < dominoes.size(); ++r) {
            // 仅判断发力点
            if (dominoes[r] == '.') {
                continue;
            }
            if (l != 0) { // 虚拟的牌不放入结果
                res += dominoes[l];
            }
            int mid = r - l - 1;
            // 区间两侧相同，受同一个力
            if (dominoes[l] == dominoes[r]) {
                res += string(mid, dominoes[l]);
            }
            // L...R型，中间不受力
            else if (dominoes[l] == 'L' && dominoes[r] == 'R') {
                res += string(mid, '.');
            }
            // R...L型，中间对半分
            else {
                res += string(mid / 2, 'R') + (mid % 2 == 1? "." : "") + string(mid / 2, 'L');
            }
            l = r;
        }
        return res;
    }
};
// @lc code=end

