class Solution:
    def minOperations(self, nums: List[int]) -> int:
        counts = {}
        count = 0
        for i in nums:
            if i in counts:
                counts[i] +=1
            else:
                counts[i] = 1
        for n in counts.values():
            if n == 1:
                return -1
            else:
                while n % 3 != 0:
                    n = n - 2
                    count += 1
                count += n//3
        return count