#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> valToIndex;

    RandomizedSet() {}
    
    bool insert(int val) {
        if(valToIndex.count(val) != 0){
            return false;
        }
        // 若不存在则将数据插入到表尾
        valToIndex[val] = nums.size();
        nums.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(valToIndex.count(val) == 0){
            return false;
        }
        // 若存在, 则先与表尾数据交换, 然后再删除表尾
        // 先修改索引表
        int popVal = valToIndex[val];
        valToIndex[nums.back()] = popVal;
        valToIndex.erase(val);
        // 再修改数据表
        nums[popVal] = nums.back();
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        int ind = rand() % (int)nums.size();
        return nums[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

