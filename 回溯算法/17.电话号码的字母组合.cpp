#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    // vector<vector<char>> maps;
    vector<string> maps = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return vector<string>();
        }
        // maps = vector<vector<char>>(10, vector<char>());
        // char ch = 'a';
        // for(int i = 2; i < 10; i++){
        //     if(i == 7 || i == 9){
        //         maps[i].push_back(ch++);
        //     }
        //     int nums = 3;
        //     while(nums-- > 0)
        //         maps[i].push_back(ch++);
        // }

        string path = "";
            track_back(digits, path, 0);
        return res;
    }

    void track_back(string &digits, string &path, int start){
        if(path.size() == digits.size()){
            res.push_back(path);
            return ;
        }
        for(char ch : maps[digits[start]-'0']){
            path.push_back(ch);
            track_back(digits, path, start+1);
            path.pop_back();
        }
    }
};
// @lc code=end

