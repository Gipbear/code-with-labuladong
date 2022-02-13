#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int t = 32;
        while(t--){
            res <<= 1;
            if(n & 1)
                res++;
            n >>= 1;
        }
        return res;
    }
};
// @lc code=end

