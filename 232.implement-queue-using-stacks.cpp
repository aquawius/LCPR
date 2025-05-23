/*
 * @lc app=leetcode.cn id=232 lang=cpp
 * @lcpr version=30204
 *
 * [232] 用栈实现队列
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class MyQueue {
public:
  MyQueue() {}

  void push(int x) { s1.push(x); }

  int pop() {
    int temp = peek();
    s2.pop();
    return temp;
  }

  int peek() {
    if (!s2.empty()) {
      return s2.top();
    }

    exchange();

    return s2.top();
  }

  bool empty() { return s1.empty() && s2.empty(); }

private:
  std::stack<int> s1;
  std::stack<int> s2;

  void exchange() {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

/*
// @lcpr case=start
// ["MyQueue", "push", "push", "peek", "pop", "empty"][[], [1], [2], [], [],
[]]\n
// @lcpr case=end

 */
