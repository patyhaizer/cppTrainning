#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>

int greaterClosest(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right)/2;
        if (nums[mid] <= target) left = mid + 1;
        else right = mid - 1;
    }
    return (left >= nums.size() ? -1 : left);
}

int getRand() {
    return std::rand() % 101;
}
void test() {
    for (int j = 0; j < 100; j++) {
        std::cout << "Test(" << j << ")"<< std::endl;
        int size = getRand();
        std::vector<int> t(size);
        std::generate(t.begin(), t.end(), getRand);
        std::sort(t.begin(), t.end());
        std::cout << "Vector" << std::endl;
        for (int i : t) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        int target = getRand();
        std::cout << "Target: " << target << std::endl;
        auto ref = upper_bound(t.begin(), t.end(), target);
        int s = greaterClosest(t, target);
        if (ref == t.end() && !t.empty()) {
            assert(s == -1);
        } else if (!t.empty()) {
            std::cout << "greaterClosest = " << t[s] << std::endl; 
            std::cout << "std result = " << *ref << std::endl;
            assert(std::distance(t.begin(), ref) == s);
        }
    }
}

int main () {
    test();
    //std::vector<int> t = {5,7,8,10,12};
    //std::cout << "greater closest: " << greaterClosest(t, 10) << std::endl;
    return 0;
}
