class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> minDist(n, INT_MAX);  // min cost to connect
        vector<bool> inMST(n, false);     // visited

        int cost = 0;
        minDist[0] = 0; // start from node 0

        for (int i = 0; i < n; i++) {
            int u = -1;

            // find node with minimum distance
            for (int j = 0; j < n; j++) {
                if (!inMST[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            // add to MST
            inMST[u] = true;
            cost += minDist[u];

            // update distances
            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int dist = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);

                    minDist[v] = min(minDist[v], dist);
                }
            }
        }

        return cost;
    }
};