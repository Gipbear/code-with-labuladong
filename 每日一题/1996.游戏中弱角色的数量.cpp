#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=1996 lang=cpp
 *
 * [1996] 游戏中弱角色的数量
 */

// @lc code=start
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // 攻击力降序, 之前有比他防御力高的就是弱
        sort(properties.rbegin(), properties.rend());
        int n = properties.size();
        int pre = 0, max_pro = properties[0][1];
        int cnt = 0;
        for(int i = 1; i < n; i++){
            // 比较时最大攻击不能相等
            if(properties[i][0] != properties[i-1][0]){
                pre = max_pro;
            }
            if(properties[i][1] < pre){
                cnt++;
            }
            else{
                max_pro = max(max_pro, properties[i][1]);
            }
        }
        return cnt;
    }
};
// @lc code=end

