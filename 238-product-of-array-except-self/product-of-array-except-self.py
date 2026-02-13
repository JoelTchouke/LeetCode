class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        res = [1] * n

        # res[i] = product of nums[0..i-1]
        prefix = 1
        for i in range(n):
            res[i] = prefix
            prefix *= nums[i]

        # multiply by product of nums[i+1..n-1]
        suffix = 1
        for i in range(n - 1, -1, -1):
            res[i] *= suffix
            suffix *= nums[i]

        return res


        