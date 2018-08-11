#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

int findTargetSumWays(std::vector<int>& nums, int S) {
    if (nums.empty()) {
        if (S == 0) return 1;
        else return 0;
    }

    int sum = 0;
    for (int i : nums) sum += i;
    if (S > sum) return 0;

    std::vector<int> past(sum+1, 0);
    std::vector<int> actual(sum+1, 0);
    // Base case
    past[0] = 1;

    //std::vector<int>* pastP = &past;
    //std::vector<int>* acturalP = &actual;

    for (int target : nums) {
       // std::cout << "target: " << target <<
        for (int i = 0; i <= sum; i++) {
            int val = abs(i+target) < past.size() ? past[abs(i+target)] : 0;
            if (abs(i-target) < past.size()) val+=past[abs(i-target)];
            actual[i] = val;
        }
        std::swap(past, actual);
    }

    return past[abs(S)];
}

int dp_1d(std::vector<int>& nums, int sum) {
    int n = nums.size();
    std::vector<int> dp(sum+1,0);
    dp[0]=1;
    for(auto num:nums) {
        for(int i=sum;i>=num;--i) {
            dp[i] += dp[i-num];
        }
    }
    
    return dp[sum];
}

int main() {
    std::vector<int> nums = {1,1,1,1,1};
	int sum = std::accumulate(nums.begin(), nums.end(), 0);
    std::cout << dp_1d(nums, sum) << std::endl;
    std::cout << findTargetSumWays(nums, 3) << std::endl;
	return 0;
}
