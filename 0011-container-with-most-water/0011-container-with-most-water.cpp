class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.empty()) return 0;
        int low = 0;
        int high = height.size() - 1;
        int maxArea = 0;
        while(high > low)
        {
            int area = min(height[high], height[low]) * (high - low);
            maxArea = max(maxArea, area);
            if (height[high] > height[low]) low++;
            else high--;
        }

        return maxArea;
    }
};