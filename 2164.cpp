//
// Created by QU on 2024/3/21.
//
#include <iostream>
#include <vector>
#include <algorithm>

/*
 * 给你一个下标从 0 开始的整数数组 nums 。根据下述规则重排 nums 中的值：

按 非递增 顺序排列 nums 奇数下标 上的所有值。
举个例子，如果排序前 nums = [4,1,2,3] ，对奇数下标的值排序后变为 [4,3,2,1] 。奇数下标 1 和 3 的值按照非递增顺序重排。
按 非递减 顺序排列 nums 偶数下标 上的所有值。
举个例子，如果排序前 nums = [4,1,2,3] ，对偶数下标的值排序后变为 [2,1,4,3] 。偶数下标 0 和 2 的值按照非递减顺序重排。
返回重排 nums 的值之后形成的数组。



示例 1：

输入：nums = [4,1,2,3]
输出：[2,3,4,1]
解释：
首先，按非递增顺序重排奇数下标（1 和 3）的值。
所以，nums 从 [4,1,2,3] 变为 [4,3,2,1] 。
然后，按非递减顺序重排偶数下标（0 和 2）的值。
所以，nums 从 [4,1,2,3] 变为 [2,3,4,1] 。
因此，重排之后形成的数组是 [2,3,4,1] 。
示例 2：

输入：nums = [2,1]
输出：[2,1]
解释：
由于只有一个奇数下标和一个偶数下标，所以不会发生重排。
形成的结果数组是 [2,1] ，和初始数组一样。


提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100
 */


using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {

        // version 1 冒泡排序
        if (nums.end() -  nums.begin() <=2){
            return nums;
        }

        /*
        for (auto si = nums.begin(); si < nums.end(); si += 2) {
            for (auto sj = si + 2; sj < nums.end(); sj += 2) {
                if (*si > *sj){
                    int temp = *si;
                    *si = *sj;
                    *sj = temp;
                }
            }
        }


        for (auto si = nums.begin() + 1; si < nums.end(); si += 2) {
            for (auto sj = si + 2; sj < nums.end(); sj += 2) {
                if (*si < *sj){
                    int temp = *si;
                    *si = *sj;
                    *sj = temp;
                }
            }
        }
        return nums;
         */

/*        int doublePtArrSize = (nums.size() + 1) / 2;
        int singlePtArrSize = nums.size() / 2;

        int *doublePtArr[doublePtArrSize];
        int i = 0;
        for (auto start = nums.begin(); start < nums.end(); start += 2) {
            doublePtArr[i++] = &(*start);
        }

        int *singlePtArr[singlePtArrSize];
        i = 0;
        for (auto start = nums.begin() + 1; start < nums.end(); start += 2) {
            singlePtArr[i++] = &(*start);
        }

        sort(doublePtArr[0], doublePtArr[doublePtArrSize]);
        sort(singlePtArr[0], singlePtArr[singlePtArrSize], greater<int>());
*/
// 原地排序偶数下标
        for (int i = 0; i < nums.size(); i += 2) {
            for (int j = i + 2; j < nums.size(); j += 2) {
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }

        // 原地排序奇数下标
        for (int i = 1; i < nums.size(); i += 2) {
            for (int j = i + 2; j < nums.size(); j += 2) {
                if (nums[i] < nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }

        return nums;
    }
};

int main(){
    vector<int> arr = vector<int> {2,6,3,67,8,34,2,6,54,3,2,3};
    Solution s = Solution();
    s.sortEvenOdd(arr);

    for (auto i = arr.begin(); i < arr.end() ; i+=2) {
        cout << *i << " " ;
    }

    cout << endl;

    for (auto i = arr.begin() + 1; i < arr.end() ; i+=2) {
        cout << *i << " " ;
    }
    return 0;
}