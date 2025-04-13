#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to find the itinerary from a list of tickets
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Graph to hold nodes and edges where the edges are sorted in a min-heap (priority queue)
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        vector<string> result; // This will hold the final itinerary

        // Build the graph
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        // DFS to build the itinerary
        findItineraryDFS(graph, result, "JFK");

        // The DFS result is in reverse order, reverse it to get the correct itinerary
        reverse(result.begin(), result.end());

        return result;
    }

    // Helper DFS function to add the itinerary in reverse order
    void findItineraryDFS(unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, vector<string>& result, string currentNode) {
        // Iterate as long as there are destinations from the current node
        while (!graph[currentNode].empty()) {
            // Get the next destination in lexical order
            string nextDestination = graph[currentNode].top();
            graph[currentNode].pop(); // Remove the edge to the next destination
            findItineraryDFS(graph, result, nextDestination); // DFS with the next node
        }
        // Add the current node to the result list
        result.push_back(currentNode);
    }
};
