class Solution(object):
    def longestPalindrome(self, s):
        n  = len(s)
        if(n <= 1):
            return s
        dp = [False for _ in range(n)]
       
        max_so_far = -1
        ret = ""
        for j in range(n):
            for i in range(j+1):
                if s[i] == s[j]:
                    if j - i >= 2:
                        dp[i] = dp[i+1]
                    else:
                        dp[i] = True
                else:
                    dp[i] = False
                    
                if dp[i] and j-i > max_so_far:
                    max_so_far = j-i
                    ret = s[i:j+1]
        return ret