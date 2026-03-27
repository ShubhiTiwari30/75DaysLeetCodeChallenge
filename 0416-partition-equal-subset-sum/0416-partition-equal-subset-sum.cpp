class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for(int num : nums) {
            sum += num;
        }
        
        // If sum is odd → not possible
        if(sum % 2 != 0) return false;
        
        int target = sum / 2;
        
        // DP array
        vector<bool> dp(target + 1, false);
        dp[0] = true;  // base case
        
        for(int num : nums) {
            // reverse loop important
            for(int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        return dp[target];
    }
};