class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        operators = {"*", "/", "+", "-"}
        stack = []
        for token in tokens:
            if token not in operators:
                stack.append(int(token))
            else:
                a = stack.pop()
                b = stack.pop()
                if token == '+':
                    stack.append(a + b)
                elif token == '-':
                    stack.append(b - a)
                elif token == '*':
                    stack.append(a * b)
                elif token == '/':
                    q = abs(b) // abs(a)
                    stack.append(q if b * a >= 0 else -q)
        return stack[0]
                
