class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        queue<pair<int,int>> q;

        // Step 1: push all 0s, mark 1s as -1
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        // directions
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        // Step 2: BFS
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            for(auto d : dir){
                int ni = i + d.first;
                int nj = j + d.second;

                if(ni >= 0 && nj >= 0 && ni < m && nj < n && mat[ni][nj] == -1){
                    mat[ni][nj] = mat[i][j] + 1;
                    q.push({ni,nj});
                }
            }
        }

        return mat;
    }
};