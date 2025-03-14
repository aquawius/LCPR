/*
 * @lc app=leetcode.cn id=225 lang=cpp
 * @lcpr version=30204
 *
 * [225] 用队列实现栈
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
class MyStack {
public:
  MyStack() {}

  void push(int x) {
    que.push(x);
    for (int i = 0; i < que.size() - 1; i++) {
      que.push(que.front());
      que.pop();
    }
  }

  int pop() {
    int val = que.front();
    que.pop();

    return val;
  }

  int top() {
    return que.front();
  }

  bool empty() {
    return que.empty();
  }

private:
  std::queue<int> que;
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

/*
// @lcpr case=start
// ["MyStack", "push", "push", "top", "pop", "empty"][[], [1], [2], [], [],
[]]\n
// @lcpr case=end

 */
