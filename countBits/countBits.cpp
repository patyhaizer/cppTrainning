#include <iostream>
#include <cmath>
//#include <math.h>
#include <vector>

std::vector<int> countBits(int num) {
    std::vector<int> result(num+1, 0);
    for (int i = 1; i <= num; i++) {
        result[i] = result[i&(i-1)] + 1;
    }
    return result;
}

int main () {
    std::vector<int> test = countBits(15);
    for (int i : test) {
        std::cout << i << " " << std::endl;
    }
    return 0;
}
