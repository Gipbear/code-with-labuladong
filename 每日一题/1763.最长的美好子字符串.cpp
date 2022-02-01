#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=1763 lang=cpp
 *
 * [1763] 最长的美好子字符串
 */

// @lc code=start
#include<algorithm>

class Solution {
public:
    // hash集合判断美好子串
    // string longestNiceSubstring(string s) {
    //     int n = s.size();
    //     string res = "", tmp = "";
    //     for(int pos = 0; pos < n; pos++){
    //         for(int len = 1; len < n-pos+1; len++){
    //             tmp = s.substr(pos, len);
    //             if(check(tmp) && tmp.size()>res.size()){
    //                 res = tmp;
    //             }
    //         }
    //     }
    //     return res;
    // }
    // bool check(string s){
    //     unordered_set<char> set1;
    //     for(char c: s){
    //         set1.insert(c);
    //     }
    //     unordered_set<char> set2;
    //     for(char c: s){
    //         if(c >= 'A' && c <= 'Z'){
    //             c = c+'a'-'A';
    //         }
    //         set2.insert(c);
    //     }
    //     return set1.size() == set2.size()*2;
    // }

    // 位运算判断美好子串
    string longestNiceSubstring(string s) {
        int n = s.size();
        string res = "";
        for(int i = 0; i < n; i++){
            int a = 0, b = 0;
            for(int j = i; j < n; j++){
                // a标记出现小写字母，b标记出现大写字母
                if('a'<=s[j] && s[j]<='z')
                    a |= (1<<(s[j]-'a'));
                else
                    b |= (1<<(s[j]-'A'));
                if(a == b && j-i+1>res.size())
                    res = s.substr(i, j-i+1);
            }
        }
        return res;
    }
};
// @lc code=end

