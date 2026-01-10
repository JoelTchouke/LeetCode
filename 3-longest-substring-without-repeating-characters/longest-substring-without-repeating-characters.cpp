class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> characters;
        int front = 0;
        int rear = 1;
        int stringSize = s.size();
        if(stringSize == 1 || stringSize == 0)
        {
            return stringSize;
        }

        characters.insert(s[front]);

        int longest = 1;
        while(rear < stringSize)
        {
            if(characters.find(s[rear]) != characters.end())
            {
                characters.erase(s[front]);
                if (front == rear)
                {
                    rear++;
                    characters.insert(s[rear]);
                }
                else
                {
                    front++;
                }
            }
            else
            {
                characters.insert(s[rear]);
                rear++;
            }
            longest = characters.size() > longest ? characters.size() : longest;
        }

        return longest;
    }
};