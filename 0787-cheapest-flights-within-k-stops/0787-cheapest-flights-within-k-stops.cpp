class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<pair<int,int>> adj[n];

        for(auto &it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, INT_MAX);

        queue<vector<int>> q;
        q.push({0, src, 0}); // {stops, node, cost}

        dist[src] = 0;

        while(!q.empty()){

            auto curr = q.front();
            q.pop();

            int stops = curr[0];
            int node = curr[1];
            int cost = curr[2];

            if(stops > k)
                continue;

            for(auto &it : adj[node]){

                int adjNode = it.first;
                int edgeCost = it.second;

                if(cost + edgeCost < dist[adjNode]){
                    dist[adjNode] = cost + edgeCost;
                    q.push({stops + 1, adjNode, dist[adjNode]});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};