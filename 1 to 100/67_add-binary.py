class Solution:
    def addBinary(self, a: str, b: str) -> str:
        def binary_to_int(num: str) -> int:
            n = 0
            j = 0
            for i in num[::-1]:
                n += int(i)*2**j
                j += 1
            return n
        
        a_int = binary_to_int(a)
        b_int = binary_to_int(b)
        s = a_int + b_int
        if s == 0:
            return "0"
        out = []
        while s > 0:
            out.append(str(s % 2))
            s = s//2
        return ''.join(out[::-1])