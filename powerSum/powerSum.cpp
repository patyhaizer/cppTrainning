#include<iostream>
#include<math.h>

int powerSum(int maxVal, int currVal, int pot, int target) {
    //std::cout << "///////////////////////////////////////////" << std::endl;
    //std::cout << "max val = " << maxVal << std::endl;
    //std::cout << "curr val = " << currVal << " - target = " << target << std::endl;
    //std::cout << "pot = " << pot << std::endl;
    //std::cout << "target = " << target << std::endl;
    if (target == 0) return 1;
    if (target < 0 || currVal > maxVal) return 0;
    return powerSum(maxVal, currVal+1, pot, target) +
           powerSum(maxVal, currVal+1, pot, target - pow(currVal,pot));
    //std::cout << "///////////////////////////////////////////" << std::endl;
}

int powerSum(int X, int N) {
    int maxVal = pow(X, 1/(double)N);
    //std::cout << "max val = " << maxVal << std::endl;
    return powerSum(maxVal, 1, N, X);

}

int main () {
    int res = powerSum(100, 3);
    std::cout << "res = " << res << std::endl;
    return 0;
}
