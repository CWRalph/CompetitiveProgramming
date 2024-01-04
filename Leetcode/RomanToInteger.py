class Solution:
    def romanToInt(self, s: str) -> int:
        values = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100,'D':500,'M':1000}
        valuesarray = 'IVXLCDM'
        total = 0
        for i in range(len(s)):
            if(i == len(s)-1):
                total += values[s[i]]

            elif valuesarray.find(s[i+1]) > valuesarray.find(s[i]):
                total -= values[s[i]]
           
            else:
                total += values[s[i]]
        return total