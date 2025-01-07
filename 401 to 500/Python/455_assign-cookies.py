class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        res , i , j = 0,len(g)-1,len(s)-1
        while i>-1 and j>-1:
            if g[i] <= s[j]:
                res += 1
                i -= 1
                j -= 1
            else:
                i -= 1
        return res