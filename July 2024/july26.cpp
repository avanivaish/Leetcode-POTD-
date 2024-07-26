#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Initialize distances based on the edges
        for(auto& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        
        // Distance from a node to itself is 0
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        
        // Floyd-Warshall algorithm to find shortest paths between all pairs of nodes
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Find the city with the smallest number of reachable cities within the distance threshold
        int minReachableCities = n;
        int cityNo = -1;
        
        for(int city = 0; city < n; city++) {
            int reachableCities = 0;
            for(int adjCity = 0; adjCity < n; adjCity++) {
                if(dist[city][adjCity] <= distanceThreshold) {
                    reachableCities++;
                }
            }
            // Update the city with the smallest number of reachable cities
            if(reachableCities <= minReachableCities) {
                minReachableCities = reachableCities;
                cityNo = city;
            }
        }

        return cityNo;
    }
};

int main() {
    Solution solution;

    int n = 4;
    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };
    int distanceThreshold = 4;

    int result = solution.findTheCity(n, edges, distanceThreshold);
    cout << "The city with the smallest number of reachable cities within the distance threshold is: " << result << endl;

    return 0;
}
