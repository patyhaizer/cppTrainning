/*Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

(1) All numbers (including target) will be positive integers.
(2) The solution set must not contain duplicate combinations.
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    void rec(const vector<int>& candidates, int target, int position,
             vector<int>& elements, vector<vector<int>>& solutions) {
        //std::cout << "target: " << target << std::endl;
        //std::cout << "position: " << position << std::endl;
        //std::cout << "elements: " << std::endl;
        //for (int i : elements) {
        //    std::cout << i << " ";
        //}
        //std::cout << endl;
        //if (target < 0) {
        //    elements.pop_back();
        //   return;
        //}
        if (target == 0) {
            //std::cout << "found solution" << std::endl;
            solutions.push_back(elements);
            return;
        }        
        for (; position < candidates.size() && target-candidates[position] >=0 ; ++position) {
            elements.push_back(candidates[position]);
            rec(candidates, target-candidates[position], position, elements, solutions);
            elements.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> elements;
        vector<vector<int>> solutions;

        std::sort(candidates.begin(), candidates.end());
        std::stack<std::pair<int, std::vector<int>>> toVisit;
        std::cout << "Adding empty list to stack" << std::endl;
        toVisit.push(std::make_pair(target, elements));
        for (int outIdx = 0; outIdx < candidates.size(); ++outIdx) {
            std::cout << "visiting: " << outIdx << std::endl;
            std::cout << "visiting element: " << candidates[outIdx] << std::endl;
            std::cout << "target: " << toVisit.top().first << std::endl;
            std::cout << "elements: " << std::endl;
                        for (int i : toVisit.top().second) {
                            std::cout << i << " " << std::endl;
                        }
            for (int index = outIdx; index < candidates.size() && toVisit.top().first - candidates[index] >= 0 ; ++index) {
                std::cout << "curr index: " << index << std::endl;
                std::cout << "TOP OUT: " << toVisit.top().first << std::endl;
                for (int i : toVisit.top().second) {
                    std::cout << i << " " << std::endl;
                }
                while (toVisit.top().first >= 0) {
                    if (toVisit.top().first == 0) {
                        std::cout << "    found solution! " << std::endl;
                        for (int i : toVisit.top().second) {
                            std::cout << i << " " << std::endl;
                        }
                        solutions.push_back(toVisit.top().second);
                        break;
                    }
                    std::pair<int, std::vector<int>> currElement = toVisit.top(); 
                    //if (currElement.first - candidates[index] < 0) {
                    //    std::cout << "do not insert new item - reached max repetitions" << std::endl;
                    //    break;
                    //}
                    std::cout << "    candidates[idx] = " << candidates[index] << std::endl;
                    std::cout << "    target: " << currElement.first << std::endl;
                    std::cout << "    Adding new element to visit: " << candidates[index] << std::endl;
                    currElement.second.push_back(candidates[index]);
                    toVisit.push(std::make_pair(currElement.first - candidates[index], currElement.second));
                    std::cout << "    toVisit.top().first = " << toVisit.top().first << std::endl;
                }
                std::cout << "top: " << toVisit.top().first << std::endl;
                std::cout << "poping... " << toVisit.top().first << std::endl;
                for (int i : toVisit.top().second) {
                    std::cout << i << " " << std::endl;
                }
                toVisit.pop();
                std::cout << "top: " << toVisit.top().first << std::endl;
                std::cout << "poping... " << toVisit.top().first << std::endl;
                for (int i : toVisit.top().second) {
                    std::cout << i << " " << std::endl;
                }
                if (!toVisit.top().second.empty()) {
                    toVisit.pop();
                }
            }
            std::cout << "outside top: " << toVisit.top().first << std::endl;
            std::cout << "outside poping... " << toVisit.top().first << std::endl;
            for (int i : toVisit.top().second) {
                std::cout << i << " " << std::endl;
            }
            if (!toVisit.top().second.empty()) {
                toVisit.pop();
            }
        }
        //rec(candidates, target, 0, elements, solutions);
        std::cout << "solutions: " << std::endl;
        for (const vector<int>& v : solutions) {
            std::cout << "[ ";
            for (int i : v) {
                std::cout << i << " ";
            }
            std::cout << "]" << std::endl;
        }
        return solutions;
    }
};

int main() {
    std::vector<int> test = {2,3,6,7};
    Solution sol;
    sol.combinationSum(test, 7);
    return 0;
}
