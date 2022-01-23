#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=2034 lang=cpp
 *
 * [2034] 股票价格波动
 */

// @lc code=start
class StockPrice {
private:
    using PII = pair<int, int>;
    // 优先队列使用<价格-时间>
    priority_queue<PII, vector<PII>, less<PII>> big_stocks;
    priority_queue<PII, vector<PII>, greater<PII>> small_stocks;
    PII cur_stock{0, 0}; // 仅记录一个就可以
    // 记录使用<时间-价格>
    unordered_map<int, int> record;
public:
    StockPrice() {}

    template <typename T>  //声明模板函数
    void update_pq(const PII &stock, T &pq){
        // 数据插入优先队列
        pq.push(stock);
        // 当优先队列的头部数据与记录中不符合, 则需要更新数据, 删除过时数据
        // 之前pq中的重复的先留着不删, 这里检查到重复了再删, 只要保证record中是最新的就行!
        while(record[pq.top().second] != pq.top().first)
            pq.pop();
    }
    
    void update(int timestamp, int price) {
        PII update_stock = {price, timestamp};
        // 记录时间戳和价格
        record[timestamp] = price;
        // 保持最新时间
        if(cur_stock.second <= timestamp)
            cur_stock = update_stock;
        // 更新最大堆和最小堆
        update_pq(update_stock, big_stocks);
        update_pq(update_stock, small_stocks);
    }
    
    int current() {
        return cur_stock.first;
    }
    
    int maximum() {
        return big_stocks.top().first;
    }
    
    int minimum() {
        return small_stocks.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end

