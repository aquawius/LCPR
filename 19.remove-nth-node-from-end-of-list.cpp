// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30204
 *
 * [19] 删除链表的倒数第 N 个结点
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

// Definition for singly-linked list.

// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode()
//         : val(0)
//         , next(nullptr)
//     {
//     }
//     ListNode(int x)
//         : val(x)
//         , next(nullptr)
//     {
//     }
//     ListNode(int x, ListNode* next)
//         : val(x)
//         , next(next)
//     {
//     }
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (!head | !head->next)
            return nullptr;

        ListNode *fast = head, *slow = head;
        for (size_t i = 0; i < n; i++) {
            fast = fast->next;
        }

        if (!fast) {
            return head->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n2\n
// @lcpr case=end
 */
