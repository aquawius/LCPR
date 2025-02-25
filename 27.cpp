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
class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        if (nums.empty())
        {
            return 0;
        }

        int headPos = 0, tailPos = nums.size() - 1;

        while (headPos <= tailPos)
        {
            if (nums[headPos] != val)
            {
                headPos++;
                continue;
            }

            if (nums[tailPos] == val)
            {
                tailPos--;
                continue;
            }

            swap(nums[headPos], nums[tailPos]);
            headPos++;
            tailPos--;
        }
        return headPos;
    }
};

int main()
{
    Solution s = Solution();
    vector<int> vec = vector<int> { 0, 1, 2, 2, 3, 0, 4, 2 };

    cout << s.removeElement(vec, 2) << endl;
    for_each(vec.begin(), vec.end(), [](int n) { cout << n << " "; });

    return 0;
}
