class Solution:
    def longestPalindrome(self, s: str) -> int:
        count_alpha = {}
        for i in s:
            if i not in count_alpha:
                count_alpha[i] = 1
            else:
                count_alpha[i] += 1
        c = []
        for i in count_alpha:
            c.append(count_alpha[i])
        c.sort(reverse = True)
        out = 0
        odd = False
        for val in c:
            if val % 2 == 0:
                out += val
            else:
                out += val-1
                odd = True
        if odd:
            out += 1
        return out