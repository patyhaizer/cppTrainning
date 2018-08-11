#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>

int smallestClosest(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right)/2;
        if (nums[mid] >= target) right = mid - 1;
        else left = mid + 1;
    }
    return right;
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
        auto ref = lower_bound(t.begin(), t.end(), target);
        int s = smallestClosest(t, target);
        if (ref == t.end() && !t.empty()) {
            if (t[0] > target) assert(s == -1);
            else assert(s == t.size() - 1);
        } else if (!t.empty()) {
            if (*ref >= target) --ref;
            std::cout << "smallestClosest = " << t[s] << std::endl; 
            std::cout << "std result = " << *ref << std::endl;
            assert(std::distance(t.begin(), ref) == s);
        }
    }
}

int main () {
    test();
    //std::vector<int> t = {5,7,8,10,12};
    //std::cout << "smallest closest: " << smallestClosest(t, 7) << std::endl;
    return 0;
}
