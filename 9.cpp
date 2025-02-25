//
// Created by QU on 2024/3/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数
是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。


示例 1：

输入：x = 121
输出：true
示例 2：

输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3：

输入：x = 10
输出：false
解释：从右向左读, 为 01 。因此它不是一个回文数。*
 */
class Solution {
public:
    bool isPalindrome(int x) {
//        if (x < 10){
//            return false;
//        }
//
//        string s =  to_string(x);
//        for (int b = s.length() - 1, a = 0; a < s.length() / 2; --b, ++a) {   // b是中间后一个下标
//            if (s[b] != s[a]){
//                return false;
//            }
//        }
//        return true;

        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNumber || x == revertedNumber / 10;

    }
};

int main(){
    Solution s = Solution();
    vector<string> strs = {"asdf", "asdf", "asdfasdf"};

    cout << std::boolalpha << s.isPalindrome(313);
    return 0;
}
