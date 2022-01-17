#include<iostream>
#include<math.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1220 lang=cpp
 *
 * [1220] 统计元音字母序列的数目
 */

// @lc code=start
class Solution {
public:
    int countVowelPermutation(int n) {
        long a=1, e=1, i=1, o=1, u=1;
        long _a, _e, _i, _o, _u;
        int m = pow(10, 9) + 7;
        for(int j = 2; j <= n; j++){
            _a = (e+i+u)%m;
            _e = (a+i)%m;
            _i = (e+o)%m;
            _o = (i)%m;
            _u = (i+o)%m;
            a = _a; e = _e; i = _i; o = _o; u = _u;
        }
        return (a+e+i+o+u)%m;
    }
};
// @lc code=end

