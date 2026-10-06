#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> overlap;

        for (const auto& v : intervals) 
        {
            if (overlap.empty() || overlap.back()[1] < v[0]) overlap.push_back(v);
            else overlap.back()[1] = std::max(overlap.back()[1], v[1]);
        }
        return overlap;
    }
};
