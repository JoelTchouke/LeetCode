class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0)
        {
            return false;
        }
        stack<int> st;
        unordered_map <char, char> mapP = {{'{','}'}, {'[',']'}, {'(',')'}};
        for(char c : s)
        {
            if(mapP.find(c) != mapP.end())
            {
                st.push(c);
            }
            else
            {
                if (st.empty()) return false;
                char topSt = st.top();
                st.pop();
                if (c != mapP[topSt]) return false;
            }
        }

        return st.size() == 0;
    }
};