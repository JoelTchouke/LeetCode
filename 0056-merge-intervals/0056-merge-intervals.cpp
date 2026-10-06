#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> overlap;
        for (std::vector<int> v : intervals)
        {
            if (overlap.empty()) 
            {
                overlap.push_back(v);
                continue;
            }
            if (overlap.back()[1] >= v[0] && v[1] >= overlap.back()[1]) overlap.back()[1] = v[1];
            else if (overlap.back()[1] >= v[0] && v[1] < overlap.back()[1]) continue;
            else overlap.push_back(v);
        }
        return overlap;
    }
};