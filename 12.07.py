class Solution:
    def __init__(self):
        self.unit = [[1000, 'M'], [900, 'CM'], [500, 'D'], [400, 'CD'], [100, 'C'], [90, 'XC'], [50, 'L'], [40, 'XL'], [10, 'X'],
                [9, 'IX'], [5, 'V'], [4, 'IV'], [1, 'I']]

    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        divs = []
        for u in self.unit:
            u = u[0]
            divs.append(int(num / u))
            num = num % u
        result = []
        for index, div in enumerate(divs):
            while div != 0:
                result.append(self.unit[index][1])
                div -= 1
        return ''.join(result)

t = Solution()
print(t.intToRoman(3) == 'III')


        