#include <algorithm>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end()); 
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(vector<int> interval : intervals)
        {
            vector<int> arr = res.back();
            if(arr[1] >= interval[0] && arr[1] <= interval[1])
            {
                res.back() = {arr[0], interval[1]};
            }
            else if(arr[0] <= interval[0] && arr[1] >= interval[1])
            {
                res.back() = arr;
            }
            else
            {
                res.push_back(interval);
            }
        }
        return res;
    }
};