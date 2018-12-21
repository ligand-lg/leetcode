class Solution:
    def isMatch(self, s, p):
        store = {}
        def helper(i,j):
            if (i, j) not in store:
                if j == len(p):
                    ans = i == len(s)
                else:
                    match = i < len(s) and (p[j] == "." or p[j] == s[i]) 
                    if j < len(p) - 1 and p[j+1] == "*":
                        ans = helper(i, j + 2) or (match and helper(i+1, j))
                    else:
                        ans = match and helper(i+1,j+1)    
                store[i,j] = ans       
            return store[i,j]
        return helper(0,0)

t = Solution()
s = "aaaaaaaaaaaaab"
p = ".*"
print(t.isMatch(s, p))
