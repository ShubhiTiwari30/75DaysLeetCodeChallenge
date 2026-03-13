class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxArea = 0;

        while(i < j) {

            int currentArea = min(height[i], height[j]) * (j - i);

            maxArea = max(maxArea, currentArea);

            if(height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }

        return maxArea;
    }
};