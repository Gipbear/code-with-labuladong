#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:

    string plusone(string s, int j){
        if(s[j] == '9')
            s[j] = '0';
        else{
            s[j] += 1;
        }
        return s;
    }

    string minusone(string s, int j){
        if(s[j] == '0')
            s[j] = '9';
        else{
            s[j] -= 1;
        }
        return s;
    }

    int openLock(vector<string>& deadends, string target) {
        if(target == "0000")
            return 0;
        unordered_set<string> deads;
        for(string s: deadends)
            deads.insert(s);
        unordered_set<string> visited;
        visited.insert("0000");

        int steps = 0;
        queue<string> q;
        q.push("0000");
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i < sz; i++){
                string cur = q.front();
                q.pop();
                if(deads.count(cur))
                    continue;
                if(cur == target)
                    return steps;
                for(int j=0; j < 4; j++){
                    string up = plusone(cur, j);
                    if(!visited.count(up)){
                        q.push(up);
                        visited.insert(up);
                    }
                    string down = minusone(cur, j);
                    if(!visited.count(down)){
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
// @lc code=end

