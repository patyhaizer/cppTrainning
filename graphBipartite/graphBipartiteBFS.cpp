#include <iostream>
#include <queue>
#include <utility>
#include <unordered_set>
#include <vector>

bool visitBFS(int node, bool firstGroup, std::vector<std::vector<int>>& graph,
              std::pair<std::unordered_set<int>, std::unordered_set<int>>& groups,
              std::queue<std::pair<int, bool>>& toVisit) {
    // Check if node was visited and is already in correct group
    if (firstGroup) {
        if (groups.first.find(node) != groups.first.end()) return true;
        else if (groups.second.find(node) != groups.second.end()) return false;
    } else {
        if (groups.second.find(node) != groups.second.end()) return true;
        else if (groups.first.find(node) != groups.first.end()) return false;
    }
    
    // If node was not visited then put it in the correct group
    if (firstGroup) groups.first.insert(node);
    else groups.second.insert(node);
    
    // Put neigbors
    for (int i = 0; i < graph[node].size(); i++) {
        toVisit.push(std::make_pair(graph[node][i], !firstGroup));
    }
    return true;
}

bool isBipartite(std::vector<std::vector<int>>& graph) {
    std::pair<std::unordered_set<int>, std::unordered_set<int>> groups;
    
    // This for is needed just to handle graph that are not fully connected
    std::queue<std::pair<int, bool>> toVisit;
    bool ret = true;
    for (int i = 0; i < graph.size(); i++) {
        if (groups.first.find(i) != groups.first.end() || groups.second.find(i) != groups.second.end()) continue;
        toVisit.push(std::make_pair(i, true));
        while (ret && !toVisit.empty()) {
            std::pair<int, bool> curr = toVisit.front();
            toVisit.pop();
            ret = visitBFS(curr.first, curr.second, graph, groups, toVisit);
        }
    }

    return ret;
}

int main() {
	std::vector<std::vector<int>> test = {{1,2}, {0,2}, {0,1}};
    std::cout << "Is bipartite? " << isBipartite(test) << std::endl;
	return 0;
}
