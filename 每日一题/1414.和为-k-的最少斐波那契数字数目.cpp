#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=1414 lang=cpp
 *
 * [1414] 和为 K 的最少斐波那契数字数目
 */

// @lc code=start
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if(k == 1 || k == 2)
            return 1;
        // 计算小于k的斐波那契数
        vector<int> fib;
        fib.push_back(1);
        fib.push_back(2);
        int tmp = 0;
        for(int i = 2; tmp < k; i++){
            tmp = fib[i-1] + fib[i-2];
            fib.push_back(tmp);
        }
        // 从后向前，贪心取数
        int cnt = 0;
        for(int i = fib.size()-1; i >= 0; i--){
            if(k - fib[i] >= 0){
                k -= fib[i];
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

