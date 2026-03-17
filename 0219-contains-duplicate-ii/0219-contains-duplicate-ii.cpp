class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp; // value → last index

        for(int i = 0; i < nums.size(); i++) {
            
            if(mp.count(nums[i])) {
                if(i - mp[nums[i]] <= k) {
                    return true;
                }
            }

            // update latest index
            mp[nums[i]] = i;
        }

        return false;
    }
};