class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        out = []
        while len(nums) > 0:
            s = set(nums)
            l = list(s)
            out.append(l)
            for i in l:
                nums.remove(i)
        return out
        