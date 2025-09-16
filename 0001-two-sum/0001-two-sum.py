class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        start = 0
        end = start + 1
        indexes = []
        while start < len(nums) - 1:
            if(end == len(nums)):
                start += 1
                end = start + 1
            if nums[start] + nums[end] == target:
                indexes = [start, end]
                break
            else:
                end += 1
        return indexes