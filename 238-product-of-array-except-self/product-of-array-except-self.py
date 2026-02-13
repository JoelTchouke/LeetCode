class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        totalCount = 1
        result = []
        numberOfZero = nums.count(0)
        if numberOfZero > 1:
            totalCount = 0
        else:
            for num in nums:
                if num != 0:
                    totalCount *= num
        for num in nums:
            if numberOfZero > 0:
                if num == 0:
                    result.append(totalCount)
                else:
                    result.append(0)
            else:
                result.append(totalCount / num)
        return result

        