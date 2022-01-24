#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start

// 递归超时

// class Solution {
// public:
//     // 两个单词的前i和j部分需要修改的步数
//     // vector<int, vector<int>> memo;
//     int minDistance(string word1, string word2) {
//         // memo = vector<int, vector<int>>(word1.size(), vector<int>(word2.size(), 0));
//         return dp(word1, word2, word1.size(), word2.size());
//     }

//     // 从后向前一一比较
//     int dp(string word1, string word2, int w1, int w2){
//         // 某个单词到了最开始之前, 则另一个单词重复删除或新增 差额 步
//         if(w1 < 0) return w2 + 1;
//         if(w2 < 0) return w1 + 1;
//         // 字母相同不用修改
//         if(word1[w1] == word2[w2]){
//             return dp(word1, word2, w1-1, w2-1);
//         }
//         else{
//             return min(
//                 dp(word1, word2, w1, w2-1) + 1, // 插入
//                 min(
//                     dp(word1, word2, w1-1, w2) + 1,  // 删除
//                     dp(word1, word2, w1-1, w2-1) + 1  // 修改
//                 )
//             );
//         }
//         // 这个随便啦, 反正也到不了
//         return -1;
//     }
// };

class Solution {
public:
    int minDistance(string word1, string word2) {
        // 两个单词的前i和j部分需要修改的步数
        int w1 = word1.size(), w2 = word2.size();
        vector<vector<int>> memo(w1+1, vector<int>(w2+1, 0));
        for(int i = 0; i <= w1; i ++){
            memo[i][0] = i;
        }
        for(int i = 0; i <= w2; i ++){
            memo[0][i] = i;
        }
        for(int i = 1; i <= w1; i++){
            for(int j = 1; j <= w2; j++){
                // 字母相同不用修改
                if(word1[i-1] == word2[j-1]){
                    memo[i][j] = memo[i-1][j-1];
                }
                else{
                    memo[i][j] = min(
                        memo[i][j-1] + 1, // 插入
                        min(
                            memo[i-1][j] + 1,  // 删除
                            memo[i-1][j-1] + 1  // 修改
                        )
                    );
                }
            }
        }
        // for(int i = 0; i <= w1; i++){
        //     for(int j = 0; j <= w2; j++)
        //         cout<<memo[i][j]<<" ";
        //     cout<<endl;
        // }
        return memo[w1][w2];
    }
};
// @lc code=end

