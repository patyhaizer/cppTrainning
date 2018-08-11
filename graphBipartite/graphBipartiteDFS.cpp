#include <iostream>
#include <utility>
#include <unordered_set>
#include <vector>

bool splitDFS(int node, bool firstGroup, std::vector<std::vector<int>>& graph,
              std::pair<std::unordered_set<int>, std::unordered_set<int>>& groups) {
    //std::cout << "@splitDFS Node = " << node << std::endl;
    //std::cout << "@splitDFS firstGroup? " << firstGroup << std::endl;
    // Check if node was visited and is already in correct group
    if (firstGroup) {
        if (groups.first.find(node) != groups.first.end()) {
            //std::cout << "@splitDFS Node was already visited and is in first group" << std::endl;
            return true;
        }
        else if (groups.second.find(node) != groups.second.end()) {
            //std::cout << "@splitDFS Node was already visited and is in second group" << std::endl;
            return false;
        }
    } else {
        if (groups.second.find(node) != groups.second.end()) {
            //std::cout << "@splitDFS Node was already visited and is in second group" << std::endl;
            return true;
        }
        else if (groups.first.find(node) != groups.first.end()) {
            //std::cout << "@splitDFS Node was already visited and is in first group" << std::endl;
            return false; 
        }
    }
    
    // If node was not visited then put it in the correct group
    if (firstGroup) {
        //std::cout << "@splitDFS Node was not visited, insert in first group" << std::endl;
        groups.first.insert(node);
    }
    else {
        //std::cout << "@splitDFS Node was not visited, insert in second group" << std::endl;
        groups.second.insert(node);
    }
    
    // Traverse trough the neighbors
    //std::cout << "@splitDFS Visit neighbors" << std::endl;
    bool ret = true;
    for (int i = 0; ret && i < graph[node].size(); i++) {
        //std::cout << "@splitDFS Visitiing neighbor " << graph[node][i] << std::endl;
        ret = splitDFS(graph[node][i], !firstGroup, graph, groups);
        //std::cout << "@splitDFS ret = " << ret << std::endl;
    }
    return ret;
}

bool isBipartite(std::vector<std::vector<int>>& graph) {
    std::pair<std::unordered_set<int>, std::unordered_set<int>> groups;
    
    // This for is needed just to handle graph that are not fully connected
    bool ret = true;
    for (int i = 0; ret && i < graph.size(); i++) {
        if (groups.first.find(i) == groups.first.end() && groups.second.find(i) == groups.second.end()) {
            //std::cout << "Start traversal for node " << i << std::endl;
            ret = splitDFS(i, true, graph, groups);
        }
    }
    return ret;
}

int main() {
	std::vector<std::vector<int>> test = {{1,2}, {0,2}, {0,1}};
    std::cout << "Is bipartite? " << isBipartite(test) << std::endl;
	return 0;
}
