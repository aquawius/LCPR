//
// Created by QU on 2024/3/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
 *
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;

        for (int j = 0; j < nums.size(); j++)
        {
            for (int i = j + 1; i < nums.size(); i++)
            {
                if (nums[j] + nums[i] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};
int main(){
    Solution s = Solution();

//    cout << s.twoSum(strs);
    return 0;
}
