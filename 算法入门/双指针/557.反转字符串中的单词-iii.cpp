#include<iostream>
#include<string>
using namespace std;

/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ' || i == s.size()-1){
                right = i-1;
                if(i == s.size() - 1)
                    right = i;
                while(left < right){
                    char tmp = s[left];
                    s[left] = s[right];
                    s[right] = tmp;
                    left++;
                    right--;
                }
                left = i+1;
            }
        }
        return s;
    }
};
// @lc code=end

