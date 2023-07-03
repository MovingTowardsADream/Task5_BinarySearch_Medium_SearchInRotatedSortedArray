#include <iostream>
#include <vector>

class Solution {
public:
    static int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, middle;
        bool flag = 1; // in array with large numbers
        if (target < nums[0])
            flag = 0; // in array with smaller numbers
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] == target) {
                return middle;
            }
            else if (flag) {
                if (nums[middle] >= nums[0]) {
                    if (nums[middle] > target) {
                        right = middle - 1;
                    }
                    else {
                        left = middle + 1;
                    }
                }
                else {
                    right = middle - 1;
                }
            }
            else if (!flag) {
                if (nums[middle] >= nums[0]) {
                    left = middle + 1;
                }
                else {
                    if (nums[middle] > target) {
                        right = middle - 1;
                    }
                    else {
                        left = middle + 1;
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    std::vector<int> nums = { 1 };
    std::cout << Solution::search(nums, 0);
}
