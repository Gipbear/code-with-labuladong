#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=2000 lang=cpp
 *
 * [2000] 反转单词前缀
 */

// @lc code=start
// class Solution {
// public:
//     string reversePrefix(string word, char ch) {
//         int n = word.size(), pos = 0;
//         for(int i = 0; i < n; i++){
//             if(word[i] == ch){
//                 pos = i;
//                 break;
//             }
//         }
//         for(int i = 0; i <= pos/2; i++){
//             char tmp = word[i];
//             word[i] = word[pos-i];
//             word[pos-i] = tmp;
//         }
//         return word;
//     }
// };

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos = word.find(ch);
        if(pos == word.npos)
            return word;
        reverse(word.begin(), word.begin()+pos+1);
        return word;
    }
};
// @lc code=end

