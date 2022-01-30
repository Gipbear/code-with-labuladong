#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] != b[0])
            return a[0] < b[0];
        return a[1] > b[1];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // 宽度升序, 高度降序
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp = {envelopes[0][1]};
        for(int i = 1; i < n; i++){
            int next = envelopes[i][1];
            // 能放就放
            if(next > dp.back()){
                dp.push_back(next);
            }
            // 放不下用一个尽可能小的元素代替
            else{
                auto p = lower_bound(dp.begin(), dp.end(), next);
                *p = next;
            }
        }
        return dp.size();
    }
    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //     int n = envelopes.size();
    //     // 宽度升序, 高度降序
    //     sort(envelopes.begin(), envelopes.end(), cmp);
    //     vector<int> height(n);
    //     for(int i = 0; i < n; i++){
    //         height[i] = envelopes[i][1];
    //     }
    //     // 最长递增子序列问题
    //     return LIS(height);
    // }

    // int LIS(vector<int> &height){
    //     int piles = 0, n = height.size();
    //     vector<int> dp(n,1);
    //     for(int i = 0; i < n; i++){
    //         int poker = height[i];
    //         int l = 0, r = piles;
    //         while(l < r){
    //             int mid = l + (r-l)/2;
    //             if(dp[mid] >= poker){
    //                 r = mid;
    //             }
    //             else{
    //                 l = mid + 1;
    //             }
    //         }
    //         if(l == piles){
    //             piles++;
    //         }
    //         dp[l] = poker;
    //     }
    //     return piles;
    // }
};
// @lc code=end

