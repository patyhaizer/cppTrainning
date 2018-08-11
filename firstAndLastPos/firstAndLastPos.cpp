#include <iostream>
#include <vector>

using namespace std;
int binarySearch(vector<int>& nums, int begin, int end, int target, bool lowerBound, bool upperBound) {
    int left = begin;
    int right = end;

    while (left <= right) {
        int mid = (left + right)/2;
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            if (lowerBound) {
                right = mid - 1;
            } else if (upperBound) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
    }
    return lowerBound ? left : (upperBound ? right : - 1);
}
vector<int> searchRange(vector<int>& nums, int target) {
    int midPosition = binarySearch(nums, 0, nums.size() - 1, target, false, false);
    std::cout << "midPos = " << midPosition << std::endl;
    if (midPosition == -1) {
        return {-1,-1};
    }
    int lowerBound = binarySearch(nums, 0, midPosition - 1, target, true, false);
    int upperBound = binarySearch(nums, midPosition + 1, nums.size() - 1, target, false, true);
    vector<int> ret;
    ret.push_back(lowerBound);
    ret.push_back(upperBound);
    return ret;
}

int main() {
    vector<int> test = {5,7,7,8,8,10};
    vector<int> result = searchRange(test, 5);
    std::cout << "[ ";
    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
    return 0;
}
