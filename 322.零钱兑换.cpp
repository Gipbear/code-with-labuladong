#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start

// dp——递归

// class Solution {
// public:
//     vector<int> memo;
//     int coinChange(vector<int>& coins, int amount) {
//         memo = vector<int>(amount+1, -66);
//         return dp(coins, amount);
//     }

//     int dp(vector<int> &coins, int amount){
//         if(amount == 0)
//             return 0;
//         if(amount < 0)
//             return -1;
//         if(memo[amount] != -66)
//             return memo[amount];
//         // 初始化为最大值
//         int res = INT_MAX;
//         for(int c : coins){
//             // 计算子问题
//             int subCoins = dp(coins, amount-c);
//             if(subCoins != -1){
//                 // 寻找子问题需要硬币数最小值
//                 res = min(subCoins+1, res);
//             }
//         }
        
//         // 无最小值说明子问题不成立
//         memo[amount] = (res == INT_MAX) ? -1 : res;
//         return memo[amount];
//     }
// };

// dp——迭代

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, amount+1);
        memo[0] = 0;
        for(int i = 0; i < amount+1; i++){
            for(int c : coins){
                if(i - c >= 0){
                    memo[i] = min(memo[i], 1 + memo[i-c]);
                }
            }
        }
        return (memo[amount] == amount+1) ? -1 : memo[amount];
    }
};


// @lc code=end

