#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n != 0){
            // if(n % 2 != 0)
                // res++;
            res += (n & 1);
            n = n >> 1;
        }
        return res;
    }
};
// @lc code=end

