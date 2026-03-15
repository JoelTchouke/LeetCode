class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left = 0
        right = len(height) - 1
        maxCapacity = 0
        while(left != right or height[left] != height[left]):
            currCapacity = min(height[left], height[right]) * (right - left)
            maxCapacity = max(maxCapacity, currCapacity)
            if(height[right] < height[left]):
                right -= 1
            else:
                left += 1
        return maxCapacity

        
        
        