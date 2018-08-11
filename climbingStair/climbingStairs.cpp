#include <iostream>
#include <vector>

long climbStairs(int n) {
    if (n < 2) return 1;
    
    std::vector<long> dp(2);
    dp[0] = 1;
    dp[1] = 2;
    
    for (int i = 2; i < n; i++) {
        long tmp = dp[1];
        dp[1] = dp[0] + dp[1];
        dp[0] = tmp;
    }
        
    return dp.back();
}

int main() {
    std::cout << "climbStais(50) = " << climbStairs(50) << std::endl;
    return 0;
}
