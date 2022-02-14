#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1)
            return 1;
        vector<int> lres(n, 1), rres(n, 1);
        // 左侧满足规则
        for(int i = 1; i < n; i++){
            if(ratings[i-1] < ratings[i]){
                lres[i] = lres[i-1] + 1;
            }
        }
        // 右侧满足规则
        for(int i = n-1; i >= 1; i--){
            if(ratings[i-1] > ratings[i]){
                rres[i-1] = rres[i] + 1;
            }
        }
        // 最小的最大值就是底线
        int res = 0;
        for(int i = 0; i < n; i++){
            res += max(lres[i], rres[i]);
        }
        return res;
    }
};
// @lc code=end

