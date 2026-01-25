using namespace std;
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        unordered_set <int> xPositions;
        for(vector <int> x : points)
        {
            if(xPositions.find(x[0]) == xPositions.end())
            {
                xPositions.insert(x[0]);
            }
        }
        int widest = 0;
        vector <int> ordered_xPosition(xPositions.begin(), xPositions.end());
        sort(ordered_xPosition.begin(), ordered_xPosition.end());
        for(int i = 1; i < ordered_xPosition.size(); i++)
        {
            if(widest < ordered_xPosition[i] - ordered_xPosition[i-1])
            {
                widest = ordered_xPosition[i] - ordered_xPosition[i-1];
            }
        }
        return widest;

    }
};