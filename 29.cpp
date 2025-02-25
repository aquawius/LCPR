//
// Created by QU on 2024/3/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;


/*
 *
 */
//class Solution {
//public:
//    int divide(int dividend, int divisor) {
//        const int MAX_MOVE = 32;
//        int leftMoveTimes = 0;
//        int subVal = 0;
//        bool isNegative = false;
//
//        // 如果是负数, 变为正数
//        if (dividend < 0) {
//            isNegative = true;
//            dividend = -dividend;
//        }
//
//        // 得到能够除以多少个divisor
//        for (; leftMoveTimes < MAX_MOVE; ++leftMoveTimes) {
//            if (dividend < (divisor << leftMoveTimes)) {
//                subVal = dividend - (divisor << (--leftMoveTimes));
//
//                cout <<(divisor << (leftMoveTimes))  << endl;
//                cout << subVal << endl;
//                break;
//            }
//        }
//
//        cout << leftMoveTimes << endl;
//
//        return subVal;
//    }
//};
//
//int main() {
//    Solution s = Solution();
//
//    cout << s.divide(100, 3);
//    return 0;
//}

// 写了一半想不太出来了, gpt帮我写了后面的东西, 大致的思路好像是正确的.

#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 使用位运算来逼近除法
        int quotient = 0; // 保存商
        bool isNegative = false;

        // 处理被除数为负数的情况
        if (dividend < 0) {
            isNegative = !isNegative; // 结果为负数
            dividend = -dividend;
        }

        // 处理除数为负数的情况
        if (divisor < 0) {
            isNegative = !isNegative; // 结果为负数
            divisor = -divisor;
        }

        // 边界处理，防止除数为0或者被除数为INT_MIN而除数为-1的情况
        if (divisor == 0 || (dividend == numeric_limits<int>::min() && divisor == -1)) {
            return numeric_limits<int>::max(); // 返回INT_MAX
        }

        // 将被除数减去除数，直到被除数小于除数
        while (dividend >= divisor) {
            int tempQuotient = 1; // 当前循环得到的商
            int tempDivisor = divisor;

            // 左移tempDivisor直到大于被除数, tempDivisor移动了几位, 同时移动商,
            // 表示商至少是这个数字, 最后处理剩下移动的一位表示的东西(再次执行就可以)
            while ((tempDivisor << 1) > 0 && (tempDivisor << 1) <= dividend) {
                tempDivisor <<= 1; // 左移
                tempQuotient <<= 1; // 商也左移
            }

            // 更新被除数和商
            dividend -= tempDivisor;        // 减去已经被计算的除尽的.
            quotient += tempQuotient;       // 商加上目前得到的结果.
            // 下一次循环, 如果大, 接着除, 知道除尽的时候, 得到的就是最终的商.
        }

        // 根据情况返回结果
        return isNegative ? -quotient : quotient;
    }
};

// 上面的解是有缺陷的, 因为可能溢出的原因, 不能处理numeric_limits<int>::max() (可能出现溢出的情况)
// 有一个思路是说统一使用负数进行处理.
//作者：Luca Zhao
//链接：https://leetcode.cn/problems/divide-two-integers/solutions/31499/zhi-xing-shi-jian-1msji-bai-100-by-luca-zhao/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main() {
    Solution s;

    // 测试用例
    cout << s.divide(100, 3) << endl; // 输出 33
    cout << s.divide(-2147483648, -1) << endl; // 输出 2147483647 (INT_MAX)
    cout << s.divide(10, 0) << endl; // 输出 2147483647 (INT_MAX)

    return 0;
}

