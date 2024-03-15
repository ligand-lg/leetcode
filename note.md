## C++ 使用
### 一行多个变量初始化
* ❌ `int a, b, c = 1, 2, 3;`。这在Python中是可以的，`a, b, c = 1, 2, 3`。golang和python类似 `a, b, c := 1, 2, 3`
* ✅ `int a = 1, b = 2, c = 3;`

### 没有 build-in string.split(" ") 方法

### int(-1) < size_t(1) => false.这是很反直觉的，因为 size_t 优先级比 int 高，会把int 转为size_t再比较。https://stackoverflow.com/questions/3642010/can-i-compare-int-with-size-t-directly-in-c

### map<char, string> m; m['a']; m.size() => 1; [key] 操作的逻辑是，获取key对应value的引用，没有的话会创建一个key。所以更建议用at