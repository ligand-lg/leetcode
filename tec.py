# 正常应该输出1，1，2，3，5，8
# 实际输出：1，1，2，5，8
a = [1,1,2,3,5,8]
for e in a:
    if e == 2:
        a.remove(2)
    print(e)
print('-------------------')
a = [1,1,2,3,5,8]
i = len(a) - 1
while i >= 0:
    ele = a[i]
    if a[i] == 2:
        a.pop(i)
    print(ele)
    i -= 1