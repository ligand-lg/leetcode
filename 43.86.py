class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if num1 == '0' or num2 == '0':
            return '0'
        base =  5
        BASENUM = pow(10, base)
        comp = []
        len_comp = 0
        i = len(num1)
        pow_i = 0
        while i > 0:
            start_i = max(i-base, 0)
            j = len(num2)
            pow_j = 0
            while j > 0:
                the_power = pow_i + pow_j
                start_j = max(j-base, 0)
                value = int(num1[start_i:i]) * int(num2[start_j:j])
                if len_comp == the_power:
                    comp.append(value)
                    len_comp += 1
                else:
                    comp[the_power] += value
                j -= base
                pow_j += 1
            i -= base
            pow_i += 1
        ans = []
        carry = 0
        for n in comp:
            n += carry
            ans.append(str(n)[0-base:])
            carry = n // BASENUM
        if carry > 0:
            ans.append(str(carry))
        ans.reverse()
        return ''.join(ans)

t = Solution()
print(t.multiply('140', '0'))
