#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2006 lang=cpp
 *
 * [2006] 差的绝对值为 K 的数对数目
 */

// @lc code=start
class Solution {
public:
    // int countKDifference(vector<int>& nums, int k) {
    //     unordered_map<int, int> num_map;
    //     for(int n: nums){
    //         num_map[n]++;
    //     }
    //     int res = 0;
    //     for(int n : nums){
    //         if(num_map.count(n)){
    //             if(num_map.count(n+k))
    //                 res += num_map[n] * num_map[n+k];
    //             if(num_map.count(n-k))
    //                 res += num_map[n] * num_map[n-k];
    //             num_map.erase(n);
    //         }
    //     }
    //     return res;
    // }
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> num_map;
        int res = 0;
        for(int n : nums){
            res += num_map[n+k];
            res += num_map[n-k];
            num_map[n]++;
        }
        return res;
    }

};
// @lc code=end

