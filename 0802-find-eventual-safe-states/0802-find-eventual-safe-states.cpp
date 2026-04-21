class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<vector<int>> rev(n);
        vector<int> outdegree(n);

        // Step 1: reverse graph + outdegree
        for(int i = 0; i < n; i++){
            outdegree[i] = graph[i].size();
            for(int v : graph[i]){
                rev[v].push_back(i);
            }
        }

        queue<int> q;

        // Step 2: push terminal nodes
        for(int i = 0; i < n; i++){
            if(outdegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> safe;

        // Step 3: BFS
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for(int prev : rev[node]){
                outdegree[prev]--;
                if(outdegree[prev] == 0){
                    q.push(prev);
                }
            }
        }

        // Step 4: sort result
        sort(safe.begin(), safe.end());
        return safe;
    }
};