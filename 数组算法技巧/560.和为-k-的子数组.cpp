#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 使用hash表来记录前缀和出现的次数
        unordered_map<int,int> presum;
        // 初始记录为 0，因为存在一个数等于 k 的情况
        presum[0] = 1;
        // count 记录个数，sum_i 计算前缀和
        int count = 0, sum_i = 0;
        for(int num: nums){
            sum_i += num;
            int sum_j = sum_i - k;
            // 相差为 k 的前缀和若存在，则相加为 k
            if(presum.find(sum_j) != presum.end()){
                // 加上此前出现 sum_j 的次数
                count += presum[sum_j];
            }
            presum[sum_i]++; // 出现次数加 1
        }
        return count;
    }
};
// @lc code=end

