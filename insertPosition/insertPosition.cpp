#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    while (left <= right) {
        mid = (left + right)/2;
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return left;
}

int main() {
    std::vector<int> test = {1,3,5,6};
    std::cout << "Position = " << searchInsert(test, 2) << std::endl;
    return 0;
}
