class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        pMap = {'{':'}', '[':']', '(':')'}
        stack = []
        for c in s:
            if c not in pMap:
                if not stack:
                    return False
                top = stack.pop()
                if pMap[top] != c:
                    return False
            else:
                stack.append(c)
                
        return  len(stack) == 0

                