class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<bool>> vis(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int row = curr[1];
            int col = curr[2];

            if (vis[row][col])
                continue;

            vis[row][col] = true;

            if (row == n - 1 && col == n - 1)
                return time;

            for (int i = 0; i < 4; i++) {

                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    !vis[nr][nc]) {

                    int newTime = max(time, grid[nr][nc]);

                    pq.push({newTime, nr, nc});
                }
            }
        }

        return -1;
    }
};