class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        
        for(int num : nums){
            freq[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // Step 2: push into heap
        for(auto &it : freq){
            pq.push({it.second, it.first});
            
            if(pq.size() > k){
                pq.pop();
            }
        }

        // Step 3: extract answer
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};