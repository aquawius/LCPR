//
// Created by QU on 2024/3/21.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
 * 编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
//        if (strs.size() <= 1){
//            return "";
//        }

        int minLength = strs[0].length();
        for (auto & str: strs) {
            minLength = min(minLength, static_cast<int>(str.length()));
        }

        int sameContentIndex = 0;
        for (int i = 0; i < minLength; ++i) {
            char c = strs[0][i];
            for (const auto &item : strs) {
                if (c != item[i]){
                    return item.substr(0, sameContentIndex);
                }
            }
            sameContentIndex++;
        }
        return strs[0].substr(0,sameContentIndex);

    }
};

int main(){
    Solution s = Solution();

    vector<string> strs = {"asdf", "asdf", "asdfasdf"};

    cout << s.longestCommonPrefix(strs);


    return 0;
}