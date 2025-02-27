// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=61 lang=cpp
 * @lcpr version=30204
 *
 * [61] 旋转链表
 */

// @lcpr-template-start
#include <cstddef>
#include <iterator>
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

//   Definition for singly-linked list.
// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (k == 0 || !head || !head->next) {
      return head;
    }
    int totalNodeNum = 1;

    ListNode *it = head;
    while (it->next) {
      totalNodeNum++;
      it = it->next;
    }

    ListNode *headPos = head;
    ListNode *tailPos = head;

    int targetMoveStep = k % totalNodeNum;
    for (int i = 0; i < targetMoveStep; i++) {
      headPos = headPos->next;
    }

    while (headPos->next) {
      headPos = headPos->next;
      tailPos = tailPos->next;
    }

    headPos->next = head;
    head = tailPos->next;
    tailPos->next = nullptr;

    return head;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2]\n4\n
// @lcpr case=end

 */
