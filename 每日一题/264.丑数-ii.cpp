#include<iostream>
#include<vector>
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
        vector<int> ans(n+1,0);
        ans[1] = 1;
        for(int i2=1, i3=1, i5=1, idx=2;idx<=n;idx++){
            // 三路依次寻找最小的丑数加入。
            int a = ans[i2]*2, b = ans[i3]*3, c = ans[i5]*5;
            int minest = min(a, min(b, c));
            if(minest == a) i2++;
            if(minest == b) i3++;
            if(minest == c) i5++;
            ans[idx] = minest;
        }
        return ans[n];
    }
};
// @lc code=end

