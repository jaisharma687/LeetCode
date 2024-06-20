class Solution:
    def convert(self, s: str, numRows: int) -> str:
        rows = {}
        for i in range(1,numRows+1):
            rows[i] = ""
        num = 1
        plus_neg = True
        if numRows <= 1:
            return s
        for i in range(len(s)):
            rows[num] += s[i]
            if not plus_neg:
                if num == 1:
                    plus_neg = True
                    num += 1
                else:
                    num -= 1
            else:
                if num == numRows:
                    plus_neg = False
                    num -= 1
                else:
                    num += 1
        out = ""
        for i in rows:
            out += rows[i]
        return out