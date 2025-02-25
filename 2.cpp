//
// Created by QU on 2024/3/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) { }

    ListNode(int x) : val(x), next(nullptr) { }

    ListNode(int x, ListNode *next) : val(x), next(next) { }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ret = new ListNode();
        ListNode *currProc = ret;
        int list1Length = getLength(l1);
        int list2Length = getLength(l2);

        int currentLine = 0;
        int n;

        bool plusFlag = false;
        while (currentLine < max(list1Length, list2Length)) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;


            n = (a + b + plusFlag) % 10;
            currProc->next = new ListNode(n);

            if ((a + b + plusFlag) >= 10) {
                plusFlag = true;
            } else {
                plusFlag = false;
            }

            currProc = currProc->next;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }

            currentLine++;
        }
        if (plusFlag == true){
            currProc->next = new ListNode(1, nullptr);
        }

        return ret->next;
    }

    int getLength(ListNode *l) {
        int i = 1;
        while (l->next) {
            i++;
            l = l->next;
        }
        return i;
    }
};

int main() {
    Solution s = Solution();
    ListNode *pListNode1 = new ListNode(2);
    pListNode1->next = new ListNode(4);
    pListNode1->next->next = new ListNode(3);

    ListNode *pListNode2 = new ListNode(5);
    pListNode2->next = new ListNode(6);
    pListNode2->next->next = new ListNode(4);


    ListNode *list = s.addTwoNumbers(pListNode1, pListNode2);
    while (list) {
        cout << list->val << " ";
        list = list->next;
    }

    return 0;
}