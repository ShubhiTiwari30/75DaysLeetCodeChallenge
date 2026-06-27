#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    vector<int> parent;

    // Find function with Path Compression
    int findRoot(int node) {
        if (parent[node] == node) {
            return node;
        }
        // Path Compression optimization
        return parent[node] = findRoot(parent[node]);
    }

    // Union function that returns false if a cycle is detected
    bool unionSets(int u, int v) {
        int rootU = findRoot(u);
        int rootV = findRoot(v);

        if (rootU == rootV) {
            return false; // Ultimate parents same hain, matlab cycle mil gayi
        }

        parent[rootU] = rootV; // Union performed
        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        // Nodes are 1-indexed, so size is n + 1
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i; // Every node is its own parent initially
        }

        // Iterate through every edge
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // If unionSets returns false, this edge creates a cycle
            if (!unionSets(u, v)) {
                return edge;
            }
        }

        return {};
    }
};