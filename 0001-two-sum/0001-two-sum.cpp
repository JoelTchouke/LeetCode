class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start = 0;
        int end = 0;
        int n = nums.size();
        while(start < n)
        {
            double sum = nums[start] + nums[end];
            if((start != end) && (sum == target))
            {
                return {start, end};
            }

            if(end == n - 1)
            { 
                end = 0;
                start++;
            }
            end++;
        }
        return {};
        
    }
};