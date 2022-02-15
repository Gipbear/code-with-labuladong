#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int> &a) {
        vector<int> ans(a.size()), tr(20010);
        for (int i = a.size() - 1; i >= 0; --i) {
            for (int j = a[i] + 10000; j; j -= j & -j)
                ans[i] += tr[j];
            for (int j = a[i] + 10001; j < 20010; j += j & -j)
                tr[j]++;
        }
        return ans;
    }
};
// @lc code=end
