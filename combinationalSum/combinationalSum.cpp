/*Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

(1) All numbers (including target) will be positive integers.
(2) The solution set must not contain duplicate combinations.
*/
#include<iostream>
#include<vector>
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
        std::sort(candidates.begin(), candidates.end());
        vector<int> elements;
        vector<vector<int>> solutions;
        rec(candidates, target, 0, elements, solutions);
        //for (const vector<int>& v : solutions) {
        //    std::cout << "[ ";
        //    for (int i : v) {
        //        std::cout << i << " ";
        //    }
        //    std::cout << "]" << std::endl;
        //}
        return solutions;
    }
};
