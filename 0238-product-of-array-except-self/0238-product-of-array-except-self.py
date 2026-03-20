class Solution(object):
    def productExceptSelf(self, nums):
        zero_count = nums.count(0)
        multiplication = 1
        res = []
        for num in nums:
            if num != 0:
                multiplication *= num
        for num in nums:
            if zero_count > 1:
                res.append(0)
            elif zero_count == 1:
                if num == 0:
                    res.append(multiplication)
                else:
                    res.append(0)
            else:
                res.append(multiplication // num)

        return res