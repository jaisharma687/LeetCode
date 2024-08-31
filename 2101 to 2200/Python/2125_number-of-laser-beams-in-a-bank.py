class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        bank_new = []
        for i in range(len(bank)):
            bank_new.append(bank[i].count("1"))
        out = 0
        for i in range(len(bank_new)):
            for j in range(i+1,len(bank_new)):
                if bank_new[i] * bank_new[j] != 0:
                    out += bank_new[i] * bank_new[j]
                    break
        return out