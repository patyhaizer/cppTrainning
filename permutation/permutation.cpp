#include <stdlib.h>     /* srand, rand */
#include <algorithm>
#include <iostream>
#include <vector>
#include <random>


int main() {
    std::vector<int> test = {1,2,3,4};

    for (int j = 0; j < 4; ++j) {
    for (int i = 0; i < test.size() - 1; i++) {
        std::swap(test[i], test[i+1]);
        for (int num : test) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    }
}
