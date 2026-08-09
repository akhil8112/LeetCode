class Solution(object):
    def canJump(self, nums):
        maxj = 0
        for i in range(len(nums)):
            if i > maxj:
                return False
            maxj = max(maxj, i + nums[i])
            if maxj >= len(nums) - 1:
                return True
        return True
                
        