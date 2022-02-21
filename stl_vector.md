


```cpp
#include <vector>
```


### 初始化

1. 定义5个 int 类型的向量，并且元素会被默认初始化 (int 默认初始化为 0)， `vec = [0,0,0,0,0]`
```cpp
std::vector<int> vec(5);
```

2. 定义5个 int 类型的向量，并且将元素初始化为2， `vec = [2,2,2,2,2]`
```cpp
std::vector<int> vec(5,2);
```

3. 定义5个 int 类型的向量，并且将元素初始化为2， `vec = [1,2,3]`
```cpp
std::vector<int> vec{1,2,3};
```

### 方法
