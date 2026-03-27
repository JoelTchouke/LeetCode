class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapT;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            mapT[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if((mapT.find(target - nums[i]) != mapT.end()) && mapT[target - nums[i]] != i)
            {
                res.push_back(i);
                res.push_back(mapT[target - nums[i]]);
                break;
            }
        }
        return res;
        
    }
};