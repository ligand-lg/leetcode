# 腾讯笔试题：已知a，b两个数为[1,10]内的整数，a不等于b。有甲乙两人，甲知道a+b，乙知道a*b。
# 甲乙开始对话：甲说我不知道，乙说我不知道。甲说我知道了，乙说我也知道了，求a，b。


def n_a_add_b(n: int) -> [(int, int)]:
    """ 给定a+b的值，返回可能的组合。
    """
    ans = []
    for a in range(int(n/2)+1, n):
        ans.append((a, n-a))
    return ans


def n_a_plus_b(n: int) -> [(int, int)]:
    """ 给定a*b的值，返回可能的组合
    """
    ans = []
    for a in range(1, 11):
        for b in range(1, a):
            if (a*b == n):
                ans.append((a, b))
    return ans


def check_ja(n: int) -> bool:
    # 和为n的a，b组合中，a*b有多种情况的可能数。目标只有一种情况。
    find = False
    for a, b in n_a_add_b(n):
        if (len(n_a_plus_b(a*b)) > 1):
            # 之前已经找到，也就情况不唯一。
            if (find):
                return False
            else:
                find = True
    return find


def check_yi(n: int) -> bool:
    find = False
    for a, b in n_a_plus_b(n):
        if (check_ja(a+b)):
            if(find):
                return False
            else:
                find = True
    return find


def main():
    for a in range(1, 11):
        for b in range(1, a):
            if len(n_a_add_b(a+b)) > 1 and len(n_a_plus_b(a*b)) > 1 and check_ja(a+b) and check_yi(a*b):
                print(a, b)


def test(a: int, b: int):
    print(n_a_add_b(a+b))
    print(n_a_plus_b(a*b))
    print(check_ja(a+b))


main()
# test(2,6)
