## C++ 使用
### 一行多个变量初始化
* ❌ `int a, b, c = 1, 2, 3;`。这在Python中是可以的，`a, b, c = 1, 2, 3`。golang和python类似 `a, b, c := 1, 2, 3`
* ✅ `int a = 1, b = 2, c = 3;`