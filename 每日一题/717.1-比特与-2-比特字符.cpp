#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int N = bits.size();
        int pos = 0;
        while (pos < N - 1) {
            pos += bits[pos] == 1 ? 2 : 1;
        }
        return pos == N - 1;
    }
};
// @lc code=end

