#include<iostream>
#include<vector>
#include<numeric>
#include<unordered_map>
#include<algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution {
public:
    bool flag = true;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(nums.size() < k){
            return false;
        }
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        if(numSum % k != 0)
        return false;

        sort(nums.begin(), nums.end());
        // 每个桶的目标
        int target = numSum / k;
        if(nums.back() > target)
            return false;
        vector<bool> used(nums.size(), false);
        return track_back(k, 0, nums, 0, used, target);
    }
    
    bool track_back(int k, int bucket, vector<int> &nums, int start, vector<bool> &used, int target){
        // 所有桶装满
        if(k == 0)
            return true;
        if(bucket == target)
            // 1. 递归下一个桶
            return track_back(k-1, 0, nums, 0, used, target);
        for(int i = start; i < nums.size(); i++){
            if(used[i])  // 数字已经被使用
                continue;
            if(nums[i]+bucket > target)  // 装不下该数字
                break;
            // 加入数字
            used[i] = true;
            bucket += nums[i];
            // 递归是否成功
            // 2. 递归下一个数字
            if(track_back(k, bucket, nums, i+1, used, target))
                return true;
            // 递归失败则拿出数字
            used[i] = false;
            bucket -= nums[i];
        }
        return false;
    }
};

// 使用备忘录数组来记录哪些元素已经被使用, 避免重复计算
// used还使用了位运算, 感觉还是上面的来的合理

// class Solution {
// public:
//     unordered_map<int, bool> memo;
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         if(nums.size() < k){
//             return false;
//         }
//         int numSum = accumulate(nums.begin(), nums.end(), 0);
//         if(numSum % k != 0)
//         return false;

//         int target = numSum / k;

//         sort(nums.begin(), nums.end());
//         // 每个桶的目标
//         if(nums.back() > target)
//             return false;
//         // vector<bool> used(nums.size(), false);

//         int used = 0;  // 使用位图技巧
//         return track_back(k, 0, nums, 0, used, target);
//     }
    
//     bool track_back(int k, int bucket, vector<int> &nums, int start, int used, int target){
//         // 所有桶装满
//         if(k == 0)
//             return true;
//         if(bucket == target){
//             // 1. 递归下一个桶
//             bool res = track_back(k-1, 0, nums, 0, used, target);
//             memo[used] = res;
//             return res;
//         }
//         if(memo.count(used)){
//             return memo[used];
//         }            
//         for(int i = start; i < nums.size(); i++){
//             if(((used >> i) & 1) == 1)  // 判断第i位是否为1
//                 continue;
//             if(nums[i]+bucket > target)  // 装不下该数字
//                 break;
//             // 加入数字
//             used |= 1 << i;  // 将第i位 置为1
//             bucket += nums[i];
//             // 递归是否成功
//             // 2. 递归下一个数字
//             if(track_back(k, bucket, nums, i+1, used, target))
//                 return true;
//             // 递归失败则拿出数字
//             used ^= 1 << i;  // 将第i位 置为0
//             bucket -= nums[i];
//         }
//         return false;
//     }
// };

// @lc code=end

