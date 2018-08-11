#include <iostream>
#include <utility>
#include <vector>
#include <queue>

class Solution {
public:
    class myComparison {
        public:
        bool operator() (const std::pair<int,int>& lhs, const std::pair<int,int>& rhs) {
            return lhs.first > rhs.first || lhs.second > rhs.second;
        }
    };
    int maxEnvelopes(std::vector<std::pair<int, int>>& envelopes) {
        std::priority_queue<std::pair<int,int>, std::vector<int>, myComparison> queue;
        return 0;
    }
};

int main() {
    return 0;
}
