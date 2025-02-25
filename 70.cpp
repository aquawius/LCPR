//
// Created by QU on 2024/3/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
 * 正确, 但是超时
 */
class Solution
{
public:
    int climbStairs(int n)
    {
        // 结束条件
        if (n == 0)
        {
            total_stairs++;
            return 0;
        }
        if (n < 0)
        {
            return 0;
        }

        climbStairs(n - 1);
        climbStairs(n - 2);
        return total_stairs;
    }

private:
    int total_stairs = 0;
};

int main()
{
    Solution s = Solution();

    cout << s.climbStairs(44);
    return 0;
}


/*class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, sum;
        for(int i = 0; i < n - 1; i++){
            sum = a + b;
            a = b;
            b = sum;
        }
        return b;
    }
};

作者：Krahets
链接：https://leetcode.cn/problems/climbing-stairs/solutions/2361764/70-pa-lou-ti-dong-tai-gui-hua-qing-xi-tu-ruwa/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/