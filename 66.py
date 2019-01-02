class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 1
        i = len(digits) - 1
        while i >=0 and carry > 0:
            tmp = digits[i] + carry
            digits[i] = tmp % 10
            carry = tmp // 10
            i -= 1
        if carry:
            digits.insert(0, carry)
        return digits

t = Solution()
print(t.plusOne([0]))
        
