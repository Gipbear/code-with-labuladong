#include<iostream>
#include <unordered_map>
#include<list>
using namespace std;

/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class Node{
public:
    int val, key;
    Node *next, *prev;
    Node(int _key, int _val){
        key = _key;
        val = _val;
    }
};

class DoubleList{
private:
    Node *head, *tail;  // 首尾虚结点
    int size;  // 双向链表长度
public:
    DoubleList(){
        this->head = new Node(0,0);
        this->tail = new Node(0,0);
        this->head->next = this->tail;
        this->tail->prev = this->head;
        this->size = 0;
    }
    // 添加结点至最后
    void addLast(Node *x){
        x->next = this->tail;
        x->prev = this->tail->prev;
        this->tail->prev->next = x;
        this->tail->prev = x;
        size++;
    }
    // 删除结点
    void remove(Node *x){
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }
    // 删除第一个结点
    Node* removeFirst(){
        if(this->head->next == tail){
            return nullptr;
        }
        Node *first = this->head->next;
        remove(first);
        return first;
    }
    // 返回链表长度
    int getsize(){
        return this->size;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> map;
    DoubleList *cache;
    int cap;

    // 将key提升为最近使用
    void makeRecently(int key){
        Node *x = this->map[key];
        // 链表删除该结点
        this->cache->remove(x);
        // 再插入到链尾来实现更新
        this->cache->addLast(x);
    }
    // 添加最近使用的元素
    void addRecently(int key, int val){
        Node *x = new Node(key, val);
        // 添加到链尾
        this->cache->addLast(x);
        // 同时更新map映射
        this->map[key] = x;
    }
    // 删除某一个key
    void deleteKey(int key){
        Node *x = this->map[key];
        // 从链表中删除
        this->cache->remove(x);
        // 同时删除map映射
        this->map.erase(key);
    }
    // 删除最久未使用的元素
    void removeLeastRecently(){
        // 链头就是最久未使用元素
        Node *deleteNode = this->cache->removeFirst();
        // 同时删除map映射
        int deleteKey = deleteNode->key;
        this->map.erase(deleteKey);
    }
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        this->cache = new DoubleList();
    }
    
    int get(int key) {
        if(map.count(key)){
            // 数据提升为最近使用
            this->makeRecently(key);
            return this->map[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // 已经存在
        if(this->map.count(key)){
            // 删除key
            this->deleteKey(key);
            // 增加key, 来更新value
            this->addRecently(key, value);
            return ;
        }
        // 空间满了, 则先删除最久未使用
        if(this->cap == this->cache->getsize()){
            this->removeLeastRecently();
        }
        this->addRecently(key, value);
        return ;
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

