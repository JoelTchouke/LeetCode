class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> arr;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int to_find = target - nums[i];
            auto it = arr.find(to_find);
            if(it != arr.end())
            {
                result.push_back(i);
                result.push_back(arr[to_find]);
            }
            else
            {
                arr[nums[i]] = i;
            }
        }
        return result;
    }
};