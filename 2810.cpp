//
// Created by QU on 2024/3/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

/*
 *
 */
class Solution {
public:
//    string finalString(string s) {
//        stack<char> charPool = stack<char>();
//        stack<char> charPoolReverse = stack<char>();
//
//        int outputLength = 0;
//        char temp;
//
//        // 这个B题, """输入第 5 个字符后，屏幕上的文本是："pon" 。""", 我以为使用\b来做终端字符清空, 真tm.
//        for (auto c : s) {
//            cout << c;
//            charPool.push(c);
//            outputLength++;
//            if ('i' == c){
//                charPool.pop();         // pop i char
//                outputLength--;
//
//                for (int i = 0; i < outputLength; ++i) {
//                    cout << '\b';
//                    temp = charPool.top();
//                    charPool.pop();
//                    cout << temp;
//                    charPoolReverse.push(temp);
//                }
//
//                for (int i = 0; i < outputLength; ++i) {
//                    charPool.push(charPoolReverse.top());
//                    charPoolReverse.pop();
//                }
//                outputLength = 0;
//            }
//        }
//        return nullptr;
//
//    }



public:
    string finalString(string s) {
        string target;
        for (char &c: s) {
            if ('i' == c) {
                std::reverse(target.begin(), target.end());
                continue;
            }
            target += c;
        }
        return target;
    }

//    void reverse(string &s) {
//        if (s.length() < 2)
//            return;
//        int left = 0, right = s.length() - 1;
//        while (left < right)
//            swap(s[left++], s[right--]);
//    }
};

int main() {
    Solution s = Solution();
//    vector<string> strs = {"asdf", "asdf", "asdfasdf"};

    string str = "string";
    cout << s.finalString(str);
    return 0;
}
