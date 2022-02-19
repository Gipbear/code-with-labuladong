#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */

// @lc code=start
class Solution {
public:
    vector<int> res;

    vector<int> pancakeSort(vector<int>& arr) {
        sort(arr, arr.size());
        return res;
    }

    void sort(vector<int> &arr, int n){
        // base case 只有一块饼则不用翻
        if(n == 1)
            return ;
        // 找到前n个中最大的数和索引maxCakeIndex
        int maxCake = 0;
        int maxCakeIndex = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] > maxCake){
                maxCake = arr[i];
                maxCakeIndex = i;
            }
        }
        // 将最大的饼翻到最前面
        reverse(arr, 0, maxCakeIndex);
        res.push_back(maxCakeIndex+1);  // 下标+1
        // 将最大的饼翻到前n个的最下面
        reverse(arr, 0, n-1);
        res.push_back(n);
        // 递归前n-1个
        sort(arr, n-1);
    }

    // 从left到right的饼翻转
    void reverse(vector<int> &arr, int left, int right){
        while(left < right){
            swap(arr[left], arr[right]);
            left++; right--;
        }
    }
};
// @lc code=end

