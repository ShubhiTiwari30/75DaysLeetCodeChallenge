class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int sum = 0;
        
        // first window
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        
        int maxSum = sum;
        
        for(int i = k; i < nums.size(); i++){
            
            sum += nums[i];      // add new element
            sum -= nums[i-k];    // remove old element
            
            maxSum = max(maxSum, sum);
        }
        
        return (double)maxSum / k;
    }
};