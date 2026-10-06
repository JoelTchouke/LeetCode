class Solution {
public:
    int search(vector<int>& nums, int target) {
        bool rotated = nums[0] > nums[nums.size() - 1];
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right)
        {
            int midpoint = left + (right - left) / 2;
            if (nums[midpoint] == target) return midpoint;
            if (!rotated) {
                if (nums[midpoint] < target) left = midpoint + 1; 
                else right = midpoint - 1;                        
            }
            else {
                if ((nums[midpoint] >= nums[0]) == (target >= nums[0])) {
                    if (nums[midpoint] < target) left = midpoint + 1;
                    else right = midpoint - 1;
                }
                else {
                    if (target >= nums[0]) right = midpoint - 1; 
                    else left = midpoint + 1;                    
                }
            }
        }
        return -1;
    }
};
