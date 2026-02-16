class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        arrOfZero = []
        arrOfNonZero = []
        for num in nums:
            if num != 0:
                arrOfNonZero.append(num)
            else:
                arrOfZero.append(num)
        count = nums.count(0)
        while count > 0:
            nums.remove(0)
            count -= 1
        nums = nums.extend(arrOfZero)