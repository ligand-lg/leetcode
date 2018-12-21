class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        s_target = []
        matched = {}
        len_p = len(p)
        len_s = len(s)
        def init_stage():
            # init s_target
            i = 0
            while i < len_p:
                while i < len_p and p[i] == '*':
                    i += 1
                if i < len_p:
                    j = i
                    while j < len_p and p[j] != '*':
                        j += 1
                    s_target.append((i, j-1))
                    i = j+1
            if len_s == 0:
                return len(s_target) == 0
            if len_p == 0:
                return False
                
            # init matched
            for t_l, t_r  in s_target:
                all_match = []
                if p.find('?', t_l, t_r+1) == -1:
                    target_str = p[t_l:t_r+1]
                    find_index = s.find(target_str)
                    while find_index > -1:
                        all_match.append((find_index, find_index + t_r - t_l))
                        find_index = s.find(target_str, find_index+1)
                else:
                    #with ? case
                    _len = t_r - t_l + 1
                    end_index = len(s) - _len
                    for _i in range(end_index+1):
                        j = 0
                        while j < _len and (s[_i+j] == p[j+t_l] or p[j+t_l] == '?'):
                            j += 1
                        if j == _len:
                            all_match.append((_i, _i+j-1))
                if len(all_match) == 0:
                    return False
                matched[(t_l, t_r)] = all_match
            return True

        def get_next_target(p_l, p_r):
            t_l , t_r = (-1, -1)
            t_len = -1
            for l, r in s_target:
                if l >= p_l and r <= p_r and r - l + 1  > t_len:
                    t_l, t_r = l, r
                    t_len = r - l +1
                elif r > p_r:
                    break
            return t_l, t_r

        def helper(s_l, s_r, p_l, p_r):
            while p_l <= p_r and s_l <= s_r and p[p_l] != '*':
                if p[p_l] != s[s_l] and p[p_l] != '?':
                    return False
                p_l += 1
                s_l += 1
            while p_l <= p_r and s_l <= s_r and p[p_r] != '*':
                if p[p_r] != s[s_r] and p[p_r] != '?':
                    return False
                p_r -= 1
                s_r -= 1

            next_t_l, next_t_r = get_next_target(p_l, p_r)
            # 递归边界条件
            # p overflow
            if p_r < p_l:
                # if s overflow -> true else false
                return s_r < s_l
            # p not overflow
            else:
                # s overflow, if p is all '*' --> true
                if s_r < s_l:
                    while p_l <= p_r:
                        if p[p_l] != '*':
                            return False
                        p_l += 1
                    return True
            # p not overflow and s not overflow
            if next_t_l == -1:
                return True
            for s_match_l, s_match_r in matched[(next_t_l, next_t_r)]:
                if s_match_l >= s_l and s_match_r <= s_r:
                    if helper(s_l, s_match_l-1, p_l, next_t_l-1) and helper(s_match_r+1, s_r, next_t_r+1, p_r):
                        return True
            return False
        return init_stage() and helper(0, len_s-1, 0, len_p-1)

t = Solution()

print(t.isMatch('', '') == True)
print(t.isMatch('', '****') == True)
print(t.isMatch('asdf', '') == False)
print(t.isMatch('acdcb', "a*c?b") == False)
print(t.isMatch('adceb', "*a*b") == True)
print(t.isMatch('cb', '?a') == False)
print(t.isMatch('aa', 'a') == False)
print(t.isMatch("c","*?*") == True)
print(t.isMatch("abce","abc*??") == False)
print(t.isMatch("babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab","***bba**a*bbba**aab**b"))
print(t.isMatch("aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba","*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*"))
print(t.isMatch("aaabbbbaaaabbabbbbaabbabaaababaababaaaaaaabaaababbaababbaababbbaaaaabaabbabbaabaababbaabababbbbbbbbabbaabbaaabaababaabaababababababbbbbbabbabbaabbaabaaaaaababaabbbaaabaaabbbbbbbbbaabaabaaabaaabbabbabb","****a*b*b**b*bbb*b**bba***b**b*b*b**ba***b*b*a*b*b*****a**aaa*baaa*ba*****a****ba*a****a**b*******a*a"))
