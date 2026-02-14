class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0
        subString = set({s[0]})
        maxSubCount = 1
        start = 0
        end = 0
        while(end < len(s)):
            if start == end:
                end += 1
                continue
            if s[end] not in subString:
                subString.add(s[end])
                end += 1
            else:
                subString.remove(s[start])
                start += 1
                subString.add(s[start])
            maxSubCount = max(len(subString), maxSubCount)


        return maxSubCount


