#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        // A B 分别反向存放字符串的字符数组
        // 符合计算顺序
        vector<int> A, B;
        int n1 = num1.size(), n2 = num2.size();
        for(int i = n1-1; i >= 0; i--)
            A.push_back(num1[i]-'0');
        for(int i = n2-1; i >= 0; i--)
            B.push_back(num2[i]-'0');
        // C是将A B各位依次相乘的结果直接存放
        // 不考虑进位
        vector<int> C(n1+n2);
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                C[i+j] += A[i]*B[j];
            }
        }
        // 处理进位
        int c = 0;
        for(int i = 0; i < n1+n2; i++){
            c += C[i];
            C[i] = c % 10;
            c /= 10;
        }
        // 过滤多余的0
        int k = n1+n2-1;
        while(k > 0 && C[k] == 0)
            k--;
        // 转化为字符串
        string res;
        while(k>=0)
            res += C[k--] + '0';
        return res;
    }
};
// @lc code=end

