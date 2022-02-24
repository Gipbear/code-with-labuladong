#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.size()-1;
        while(left < right){
            // 跳过左右两侧非字母字符
            while(left < right && !isalpha(s[left])) left++;
            while(left < right && !isalpha(s[right])) right--;
            // 交换字母
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }
};
// @lc code=end

