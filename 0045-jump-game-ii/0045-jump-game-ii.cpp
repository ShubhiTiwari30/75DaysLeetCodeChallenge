class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;   // boundary of current jump
        int farthest = 0;     // max we can reach

        for(int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if(i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};
