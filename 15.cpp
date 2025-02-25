#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 他奶奶的, 不知道是谁, 故意写了非常长的内容, 导致有超时

class Solution {
public:

    // 自定义比较函数对象
    struct SortedVectorCompare {
        bool operator()(const std::vector<int> &v1, const std::vector<int> &v2) const {
            return v1 == v2;
        }
    };

    struct VectorCompare {
        bool operator()(const std::vector<int> &v1, const std::vector<int> &v2) const {
            std::vector<int> sorted_v1 = v1;
            std::vector<int> sorted_v2 = v2;
            std::sort(sorted_v1.begin(), sorted_v1.end());
            std::sort(sorted_v2.begin(), sorted_v2.end());
            return sorted_v1 == sorted_v2;
        }
    };

    vector<vector<int>> threeSum(vector<int> &nums) {
        // 先排序, 保证set添加的相同
        // std::sort(nums.begin(), nums.end());

        vector<vector<int>> vec;
        std::set<std::vector<int>> tripletsSet;
//        std::set<std::vector<int>, VectorCompare> tripletsSet;
        // 如果没有排序, 上面的set去重的得修改成比较每个三元组的内容, 我使用的是对这三个排序然后通过vector的operator==(), \
        // 你也可以使用map判定是不是相等, 相对与vector自带的排序效率应该更高

        for (int i = 0; i < nums.size() - 2; ++i) {
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        std::vector<int> item{nums[i], nums[j], nums[k]};

                        // 因为对item排序，保证元素顺序一致
                        std::sort(item.begin(), item.end());

                        // 向set中插入排序后的三元组, second 表示是否插入成功.
                        if (tripletsSet.insert(item).second) {
                            vec.push_back(item);
                        }
                    }
                }
            }
        }
        return vec;
    }
};


int main(){
    Solution s = Solution();
//    vector<string> strs = {"asdf", "asdf", "asdfasdf"};

//    cout << s.threeSum(strs);
    return 0;
}
