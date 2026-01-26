using namespace std;
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector <int> ordered_xPosition;
        for(vector <int> x : points)
        {
            ordered_xPosition.push_back(x[0]);
        }
        int widest = 0;
        sort(ordered_xPosition.begin(), ordered_xPosition.end());
        for(int i = 1; i < ordered_xPosition.size(); i++)
        {
            widest = max(widest, (ordered_xPosition[i] - ordered_xPosition[i - 1]));
        }
        return widest;

    }
};