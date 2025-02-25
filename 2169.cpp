//
// Created by QU on 2024/3/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int count = 0;

    int countOperations(int num1, int num2) {
        if (num1> num2){
            if (num1 == 0 || num2 == 0){
                return count;
            }
            count ++;
            return countOperations( num1- num2, num2);
        } else {

            if (num1 == 0 || num2 == 0){
                return count;
            }
            count ++;
            return countOperations(num1, num2 - num1);
        }
    }
};

int main(){
    Solution s = Solution();

    int int1 = 2;
    int int2 = 3;
    cout << s.countOperations(int1,int2);


    return 0;
}