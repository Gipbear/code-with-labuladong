#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m)
            return false;
        // 只有26个字母
        vector<int> alpha(26, 0);
        // 计数s1中字符个数
        for(char s : s1){
            alpha[s-'a']++;
        }
        int left = 0;
        for(int right = 0; right < m; right++){
            // 右侧扩张匹配一个, 计数减一
            int x = s2[right]-'a';
            alpha[x]--;
            // 右端点计数为负数, 说明存在不合理或过多的重复字母, 此时左侧缩小
            while(alpha[x] < 0){
                alpha[s2[left]-'a']++;
                left++;
            }
            // 窗口大小合适
            if(right-left + 1 == n)
                return true;
        }
        return false;
    }
};
// @lc code=end

