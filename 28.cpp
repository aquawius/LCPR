#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
 * 倒是可以暴力破解, 但是我知道有KMP这种算法, 看看人家怎么个思路
 * https://zhuanlan.zhihu.com/p/83334559
 */
//class Solution {
//public:
//    int strStr(string haystack, string needle) {
//        // 先试试暴力算法
//        // 对长串的所有字符进行遍历
//        for (int i = 0; i < haystack.length(); ++i) {
//            // 如果处理到末尾没有发现, needle + i的长度最终会超过haystack的长度, 防止数组越界, 使用min加一个限制
//            for (int j = 0; j < min(needle.length(), haystack.length() - i); ++j) {
//                if (needle[j] != haystack[i + j]) {
//                    // 不匹配, 结束后续的匹配, 外层进行下一层循环
//                    break;
//                } else {
//                    // 如果能进入到这里, 就说明已经成功匹配了一次或多次
//                    if (j == needle.length() - 1) {
//                        // 如果能够完全匹配, 进入到这里, 返回当前索引i;
//                        return i;
//                    }
//                    // 没有完全匹配, 继续下一个字符的比较
//                    continue;
//                }
//            }
//        }
//        // 如果没有匹配的结果, 返回-1
//        return -1;
//    }
//};



class Solution {
public:
    int strStr(string haystack, string needle) {
        auto it = search(haystack.begin(),haystack.end(), needle.begin(), needle.end());
        if (it == haystack.end()){
            return -1;
        }
        else {
            return it - haystack.begin();
        }
    }
};

int main() {
    Solution s = Solution();

//    cout << s.strStr("hello", "ll");
//    cout << s.strStr("a", "a");
//    cout << s.strStr("leetcode", "leetco");
    cout << s.strStr("aquaius code make me great again.", "great again.");
    return 0;
}
