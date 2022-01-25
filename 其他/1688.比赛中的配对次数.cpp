/*
 * @lc app=leetcode.cn id=1688 lang=cpp
 *
 * [1688] 比赛中的配对次数
 */

// @lc code=start
class Solution {
public:
    int numberOfMatches(int n) {
        // int res = 0;
        // while(n != 1){
        //     if(n % 2 == 0){
        //         n = n/2;
        //         res += n;
        //     } else {
        //         n = n/2 + 1;
        //         res += n-1;
        //     }
        // }
        // return res;
        return n-1;
    }
};
// @lc code=end

