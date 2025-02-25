//
// Created by QU on 2024/3/22.
//

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


/*
 *
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//        int currentProcess = 0;
//
//        string first;
//        string second;
//
//
//        int firstProgress = 0;
//        int secondProgress = 0;
//        for (int i = firstProgress; i < s.length(); ) {
//            // 将没有出现过的字符添加到hashtable.
//            if (isUnique(s[i])) {
//                i++;
//                continue;
//            } else {
//                // 出现了重复的字符, 记录这个子串.
//                first = s.substr(firstProgress, i - firstProgress);
//                if (i + first.length() > s.length()){
//                    break;
//                }
//
//                charCount.clear();
//                // 从这个子串首的位置 + 1, 开始寻找比这个串长的串.
//                secondProgress = firstProgress + 1;
//                for (int j = secondProgress; j < s.length();) {
//                    if (isUnique(s[j])) {
//                        j++;
//                        continue;
//                    } else {
//                        // 出现了重复的字符, 记录下来这个子串
//                        second = s.substr(secondProgress, j - secondProgress);
//                        if (second.length() < first.length()) {
//                            // 不满足最长的子串, +1 继续查找
//                            charCount.clear();
//                            secondProgress++;
//                            j = secondProgress;
//                            continue;
//                        } else {
//                            // 满足最长子串, 将index记录下来, break让外层循环更新first的值.
//                            i = firstProgress = secondProgress;
//                            charCount.clear();
//                            break;
//                        }
//                    }
//                }
//            }
//            // 在这里是正确的, 但是不知道结束条件应该怎样写.
//            // TODO: 此题使用我自己的思路做法放弃.
//        }
//        cout << first << endl;
//
//        return first.length();


// 根据题解, 使用滑动窗口实现


        std::unordered_map<char, int> hash;

        // unordered_map<char, int> 中的 int 类型值是用来记录字符的索引位置的，它的作用是在发现重复字符时，帮助我们更新滑动窗口的左边界。

        int ans = 0, left = 0;

        int i;
        for (i = 0; i < s.length(); ++i) {
            char cur = s[i];
            // 这个字符出现过, 而且索引位置大于等于left
            if(hash.count(cur) && hash[cur] >= left){
                ans = max(ans, i - left);
                left = max(left, hash[cur] + 1);
            }
            hash[cur] = i;
        }
        return max(ans, i - left);

    }
};

int main() {
    Solution s = Solution();
    string str = "abcabcbb";
//    string str = "pwwkew";

    cout << s.lengthOfLongestSubstring(str);
    return 0;
}