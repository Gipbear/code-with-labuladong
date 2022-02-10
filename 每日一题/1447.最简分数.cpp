#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1447 lang=cpp
 *
 * [1447] 最简分数
 */

// @lc code=start
class Solution {
public:
    // 最大公约数，a > b
    int gcd(int a, int b){
        while(b != 0){
            int t = a;
            a = b;
            b = t % b;
        }
        return a;
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for(int i = 1; i < n; i++){
            for(int j = i+1; j <= n; j++){
                if(gcd(j, i) == 1)
                    res.push_back(to_string(i) + "/" + to_string(j));
            }
        }
        return res;
    }
};
// @lc code=end

