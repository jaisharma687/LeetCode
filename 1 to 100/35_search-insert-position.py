class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        found = False
        for i in nums:
            if i == target:
                found = True
        if found:
            return nums.index(target)
        else:
            nums.append(target)
            nums.sort()
            return nums.index(target)
        