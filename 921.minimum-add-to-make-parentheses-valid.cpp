/*
 * @lc app=leetcode.cn id=921 lang=cpp
 * @lcpr version=30204
 *
 * [921] 使括号有效的最少添加
 */

// @lcpr-template-start
#include <type_traits>
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
  int minAddToMakeValid(string s) {
    int count = 0;
    std::stack<char> stack;

    for (char ch : s) {
      if (ch == '(') {
        if (stack.empty()) {
          stack.push(ch);
        } else {
          if (stack.top() == ')') {
            stack.pop();
          } else {
            stack.push(ch);
          }
        }
      }
      if (ch == ')') {
        if (stack.empty()) {
          count++;
        } else {
          if (stack.top() == '(') {
            stack.pop();
          } else {
            count++;
          }
        }
      }
    }

    return stack.size() + count;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "())"\n
// @lcpr case=end

// @lcpr case=start
// "((("\n
// @lcpr case=end

 */
