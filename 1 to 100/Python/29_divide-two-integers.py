class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if (dividend > 0 and divisor > 0) or (dividend < 0 and divisor < 0):
            q = dividend // divisor
        else:
            q = math.ceil(dividend / divisor)
        if q > 2**31 - 1:
            return 2**31 - 1
        elif q < -2**31:
            return -2**31
        else:
            return q 