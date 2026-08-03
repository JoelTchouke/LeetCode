class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_counter = 0;
        int mult_no_zero = 1;
        std::vector<int> res;
        for (auto& num : nums) 
        {
            if (num == 0) zero_counter++;
            else mult_no_zero *= num;
        }
        if (zero_counter > 1) return std::vector<int> (nums.size(), 0);

        for (int num : nums)
        {
            if (zero_counter)
            {
                if(num == 0) res.push_back(mult_no_zero);
                else res.push_back(0);
            }
            else 
            {
                res.push_back(mult_no_zero / num);
            }
        }

        return res;

    }
};