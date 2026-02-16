class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        matches = {'{':'}', '(':')', '[':']'}
        for p in s:
            if p in matches :
                stack.append(p)
            else:
                if not stack:
                    return False
                top = stack.pop()
                if matches[top] != p:
                    return False   
        return not stack