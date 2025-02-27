/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30204
 *
 * [150] 逆波兰表达式求值
 */

// @lcpr-template-start
#include <asm-generic/errno.h>
#include <string>
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
class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    std::stack<int> stack;
    std::unordered_map<char, std::function<int(int, int)>> symbols{
        {'+', [](int a, int b) { return a + b; }},
        {'-', [](int a, int b) { return a - b; }},
        {'*', [](int a, int b) { return a * b; }},
        {'/', [](int a, int b) { return a / b; }}};

    for (const string &s : tokens) {
      if (s.size() == 1 && symbols.find(s[0]) != symbols.end()) {
        // 运算是有顺序的
        int b = stack.top();
        stack.pop();
        int a = stack.top();
        stack.pop();
        int result = symbols[s[0]].operator()(a, b);
        stack.push(result);
      } else {
        stack.push(stoi(s));
      }
    }

    return stack.top();
  };
};
// @lc code=end

/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */
