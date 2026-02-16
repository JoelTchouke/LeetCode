class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        matches = {'{':'}', '(':')', '[':']'}
        for p in s:
            if len(stack) == 0 and p not in matches:
                return False
            if p in matches :
                stack.append(p)
            if len(stack) != 0 and p not in matches:
                top = stack.pop()
                if(matches[top] != p):
                    return False
            
        return len(stack) == 0