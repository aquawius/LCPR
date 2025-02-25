//
// Created by QU on 2024/3/26.
//

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


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) { }

    ListNode(int x) : val(x), next(nullptr) { }

    ListNode(int x, ListNode *next) : val(x), next(next) { }
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
//        if (list1 == nullptr){
//            return list2;
//        } else if (list2 == nullptr){
//            return list1;
//        }

        ListNode * dum  = new ListNode();
        ListNode * cur = dum;

        while (list1 != nullptr && list2 != nullptr){
            if (list1->val < list2->val){
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;

        }
        // 其中一个为nullptr, 剩下的直接合并

        cur->next = list1 != nullptr ? list1 : list2;
//        cur->next = list1 != nullptr ? list1 : list2;
//        上面的这句话可以代替上面的if xxx = nullptr........
        return dum->next;   // 浪费一个空间 val=0, next=HEAD , 为了放一个头指针.
    }
};


int main() {
    Solution s = Solution();

//    cout << s.mergeTwoLists(strs);
    return 0;
}