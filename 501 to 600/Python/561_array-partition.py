class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        out = []
        for i in range(0,len(nums)-1,2):
            out.append((nums[i],nums[i+1]))
        s = 0
        for i in out:
            s += min(i)
        return s