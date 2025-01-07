class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        out = [char for char in s][::-1]
        while out[0] == " ":
            out.remove(" ")
        if len(out) <2:
            return len(out)
        for i in range(len(out)):
            if out[i] == " ":
                break
            if i == len(out) -1:
                i += 1
                break
        return i