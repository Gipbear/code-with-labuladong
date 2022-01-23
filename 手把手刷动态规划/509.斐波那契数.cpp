#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start

// dp备忘录解法

// class Solution {
// public:
//     vector<int> memo;
//     int fib(int n) {
//         if(n == 0)
//             return 0;
//         if(n == 1 || n == 2)
//             return 1;
//         memo = vector<int>(n+1, 0);
//         memo[1] = 1;
//         memo[2] = 1;
//         return dp(n);
//     }

//     int dp(int n){
//         if(memo[n] != 0)
//             return memo[n];
//         return dp(n-1) + dp(n-2);
//     }
// };


// 迭代解法

class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        vector<int> memo(n+1, 0);
        memo[1] = 1;
        memo[2] = 1;
        for(int i = 3; i <= n; i++){
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo[n];
    }
};

// @lc code=end

