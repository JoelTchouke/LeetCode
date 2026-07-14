class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> numsHash;
        vector<int> result;
        for (size_t index = 0; index < nums.size(); ++index) 
        {
            int lookingFor = target - nums[index];
            auto it = numsHash.find(lookingFor);
            if (it != numsHash.end()) {
                result.push_back(it -> second);
                result.push_back(index);
                break;
            }
            numsHash[nums[index]] = index;
        }
        return result;
    }
};