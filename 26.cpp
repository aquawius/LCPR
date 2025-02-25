//
// Created by QU on 2024/3/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
 *
 */
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
//        for (auto start = nums.begin(); start <= nums.end();) {
//            if ((start + 1) < nums.end()){
//                if (*start == *(start+1)) {
//                    nums.erase(start+1);
//                    continue;
//                }
//            }
//            start++;
//        }

/*
        int left, right = 1;
        while (right < nums.size()) {
            if (nums[left] == nums[right]) {
                right++;
            }else {
                nums[++left] = nums[right];
                right++;
            }
        }

        return left;
    }
*/

        return unique(nums.begin(),nums.end()) - nums.begin();
};

int main() {
    Solution s = Solution();
    vector<int> vect = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    cout << s.removeDuplicates(vect);
    return 0;
}
