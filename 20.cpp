//
// Created by QU on 2024/3/26.
//
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


/*
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。


示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false


提示：

1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成
 */
class Solution {
public:
    bool isValid(string str) {
        auto m = map<char,char>({{'(',')'},{'[',']'},{'{','}'}});

        auto s = stack<char>();
        for (char c : str){
            if (c == '(' || c == '[' || c == '{'){
                s.push(c);
                continue;
            }
            if (c == ')' || c == ']' || c == '}'){
                if (s.empty()){
                    return false;
                }

                if (m[s.top()] == c){
                    s.pop();
                    continue;
                }
                else return false;
            }
        }
        return s.empty();
    }
};


int main() {
    Solution s = Solution();
//    vector<string> strs = {"asdf", "asdf", "asdfasdf"};
    cout << boolalpha << s.isValid("){") << endl;
    return 0;
}
