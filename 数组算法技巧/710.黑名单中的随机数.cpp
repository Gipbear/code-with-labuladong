#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 */

// @lc code=start
class Solution {
private:
public:
    // 黑名单数据的映射索引
    unordered_map<int, int> mapping;
    int len;  // 除去黑名单数据后还剩的数据长度
    Solution(int n, vector<int>& blacklist) {
        len = n - blacklist.size();
        for(int b : blacklist){
            mapping[b] = 666;  // 初始随意
        }
        int last = n - 1;  // 从后往前依次寻找合法的映射位置
        for(int b : blacklist){
            if(b >= len)  // 长度外的不必索引
                continue;
            // 跳过黑名单数据
            while(mapping.count(last)){
                last--;
            }
            // 黑名单数据映射到合法数字
            mapping[b] = last;
            last--;
        }
    }
    
    int pick() {
        int index = rand() % len;
        // 黑名单中的数据, 映射合法索引
        if(mapping.count(index)){
            return mapping[index];
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

