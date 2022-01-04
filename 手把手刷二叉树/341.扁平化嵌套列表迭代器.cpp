#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
    public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    vector<NestedInteger> &getList() const;
};

// @lc code=start

class NestedIterator {
private:
    vector<int> list;
    int idx = 0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        analysis(nestedList);
    }

    // 
    void analysis(vector<NestedInteger>& l){
        int n = l.size();
        for(int i = 0; i < n; i++){
            if(l[i].isInteger()){
                list.emplace_back(l[i].getInteger());
            }
            else{
                analysis(l[i].getList());
            }
        }
    }
    
    int next() {
        return list[idx++];
    }
    
    bool hasNext() {
        return idx < list.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

