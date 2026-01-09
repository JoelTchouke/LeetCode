class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, char> characters;
        int front = 0;
        int rear = 1;
        if(s.size() == 1)
        {
            return 1;
        }
        if(s.size() == 0)
        {
            return 0;
        }

        characters[s[front]] = s[front];

        int longest = 1;
        while(rear < s.size())
        {
            if(characters.find(s[rear]) != characters.end())
            {
                characters.erase(s[front]);
                if (front == rear)
                {
                    rear++;
                    characters[s[rear]] = s[rear];
                }
                else
                {
                    front++;
                }
            }
            else
            {
                characters[s[rear]] = s[rear];
                rear++;
            }
            longest = characters.size() > longest ? characters.size() : longest;
        }

        return longest;
    }
};