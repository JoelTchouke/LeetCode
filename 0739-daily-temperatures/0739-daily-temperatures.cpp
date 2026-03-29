class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<vector<int>> st;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++)
        {
            if (!st.empty())
            {
                vector<int> previousDayTemp = st.top();
                while (!st.empty() && temperatures[i] > previousDayTemp[0])
                {
                    res[previousDayTemp[1]] = i - previousDayTemp[1];
                    st.pop();
                    if(!st.empty()) previousDayTemp = st.top();
                }
            }
            st.push({temperatures[i], i});
        }

        return res;
        
    }
};