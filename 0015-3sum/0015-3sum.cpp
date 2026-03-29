class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int previousOffset;
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++)
        {
            if(previousOffset == nums[i]) continue;
            int low = i + 1;
            int high = nums.size() - 1;

            while(high > low)
            {
                int sum = nums[i] + nums[low] + nums[high];
                if(sum > 0) high--;
                else if (sum < 0) low++;
                else
                {
                    vector<int> toBeAdded = {nums[i], nums[low], nums[high]};
                    if(res.empty() || (!res.empty() && res.back() != toBeAdded)) res.push_back(toBeAdded);
                    low++;
                }
            }
            previousOffset = nums[i];
        }
        return res;
    }
};