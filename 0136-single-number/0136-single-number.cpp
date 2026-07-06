class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_nums=0;

        for(int i=0;i<n;i++){
            xor_nums ^= nums[i];
        }

        return xor_nums;
    }
};
