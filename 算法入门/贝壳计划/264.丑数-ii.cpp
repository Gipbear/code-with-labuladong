#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;
        vector<int> res(2,1);
        int p2 = 1, p3 = 1, p5 = 1;
        for(int i = 2; i <= n; i++){
            int tmp = min(res[p2]*2, min(res[p3]*3, res[p5]*5));
            res.push_back(tmp);
            if(tmp % 2 == 0) p2++;
            if(tmp % 3 == 0) p3++;
            if(tmp % 5 == 0) p5++;
        }
        return res[n];
    }
};
// @lc code=end

