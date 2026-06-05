# 最常用的 10 个 STL 元编程工具（附作用）

全部来自 `<type_traits>`，是元编程基石。

## ~~1. `std::is_void<T>`~~

- **类别**：类型检查模板
- **作用**：判断类型 T 是否为 `void`
- **返回**：编译期布尔值（`true_type` / `false_type`）
- **练习点**：基础偏特化

## ~~2. `std::is_pointer<T>`~~

- **类别**：类型检查模板
- **作用**：判断 T 是否是指针类型（`int*`, `char*` 等）
- **练习点**：偏特化匹配模式

## ~~3. `std::is_integral<T>`~~

- **类别**：类型检查模板
- **作用**：判断是否为整数类型（`int, bool, char, long` 等）
- **练习点**：多条件偏特化

## ~~4. `std::remove_reference<T>`~~

- **类别**：类型转换工具
- **作用**：把 `T&`、`T&&` 变成 `T`
- **练习点**：引用剥离 + 类型别名

## ~~5. `std::remove_pointer<T>`~~

- **类别**：类型转换工具
- **作用**：把 `T*` 变成 `T`
- **练习点**：指针类型偏特化匹配

## ~~6. `std::is_same<T, U>`~~

- **类别**：类型相等判断
- **作用**：判断 T 和 U 是不是同一个类型
- **练习点**：基础模板 + 全特化



## ~~7. `std::conditional<B, T, F>`~~

- **类别**：编译期 if
- **作用**：如果 B 为 true，结果是 T；否则是 F
- **练习点**：编译期分支逻辑

## ~~8. `std::is_class<T>`~~

- **类别**：类型检查
- **作用**：判断 T 是否是 class/struct/union
- **练习点**：SFINAE 基础技巧（稍微进阶）



------



## 11. `std::decay<T>`

- **类别**：类型退化工具
- **作用**：模拟 C++ 中「按值传递」时的类型退化规则，将复杂类型转换为对应的普通值类型，是组合型元编程的典型应用（依赖 `std::remove_reference`、`std::remove_cv`、`std::remove_extent` 等基础工具）。
- **输入**：任意类型 T（包括引用、数组、函数类型、带 cv 限定符的类型等）。
- **输出**：按如下规则退化后的类型：
  1. 先剥离 T 的引用属性（等价于 `std::remove_reference_t<T>`）；
  2. 对剥离引用后的类型，若为数组类型（如 `int[5]`、`char[]`），则退化为对应的指针类型（`int*`、`char*`）；
  3. 若为函数类型（如 `void(int)`），则退化为对应的函数指针类型（`void(*)(int)`）；
  4. 对剩余类型（非数组 / 函数类型），剥离 const/volatile 限定符（等价于 `std::remove_cv_t<...>`）；
- **示例**：
  - `std::decay_t<int&>` → `int`
  - `std::decay_t<const int[3]>` → `const int*`
  - `std::decay_t<void(int)>` → `void(*)(int)`
  - `std::decay_t<volatile double&&>` → `double`
- **练习点**：组合型元编程（综合引用剥离、数组 / 函数类型处理、cv 限定符移除）。

## ~~12. `std::invoke_result<F, Args...>`~~

- **类别**：类型推导工具
- **作用**：在编译期推导「可调用对象 F 传入参数 Args... 调用后」的返回类型，支持所有可调用对象类型，无需实际执行调用。
- **输入**：
  - F：可调用对象类型（函数指针、函数引用、lambda 类型、仿函数类型、成员函数指针、成员变量指针等）；
  - Args...：调用 F 时传入的参数类型列表（变长模板参数）。
- **输出**：F (Args...) 调用结果的类型（通过 `std::invoke_result_t<F, Args...>` 获取）；若 F 无法被 Args... 类型的参数调用，则触发编译错误。
- **示例**：
  - `std::invoke_result_t<int(*)(double), double>` → `int`（普通函数指针）；
  - `std::invoke_result_t<decltype(&std::string::size), std::string>` → `std::string::size_type`（成员函数指针）；
  - `std::invoke_result_t<decltype(&std::string::data), const std::string>` → `const char*`（const 成员函数指针）；
  - `std::invoke_result_t<decltype(&std::vector<int>::size), std::vector<int>&>` → `std::vector<int>::size_type`（成员函数指针 + 引用参数）；
- **练习点**：变长模板、SFINAE 技巧、各类可调用对象的返回值推导。

## 13. `std::is_member_function_pointer<T>`

- **类别**：类型检查模板
- **作用**：在编译期判断类型 T 是否为「成员函数指针类型」（包括普通成员函数、const 成员函数、volatile 成员函数、const volatile 成员函数的指针）。
- **输入**：任意类型 T。
- **输出**：编译期布尔值（继承自 `std::true_type` 或 `std::false_type`）：
  - 若 T 是成员函数指针类型 → `true_type`；
  - 否则 → `false_type`；
- **示例**：
  - `std::is_member_function_pointer_v<void (std::string::*)()>` → `true`（普通成员函数指针）；
  - `std::is_member_function_pointer_v<int (MyClass::*)(double) const>` → `true`（const 成员函数指针）；
  - `std::is_member_function_pointer_v<int MyClass::*>` → `false`（成员变量指针，非成员函数指针）；
  - `std::is_member_function_pointer_v<void (*)(int)>` → `false`（普通函数指针，非成员）；
- **练习点**：成员函数指针类型的偏特化匹配、SFINAE 基础。

## 14. `std::is_member_object_pointer<T>`

- **类别**：类型检查模板
- **作用**：在编译期判断类型 T 是否为「成员变量指针类型」（指向类 / 结构体 / 联合体的非函数成员的指针）。
- **输入**：任意类型 T。
- **输出**：编译期布尔值（继承自 `std::true_type` 或 `std::false_type`）：
  - 若 T 是成员变量指针类型 → `true_type`；
  - 否则 → `false_type`；
- **示例**：
  - `std::is_member_object_pointer_v<int MyClass::*>` → `true`（普通成员变量指针）；
  - `std::is_member_object_pointer_v<const std::string MyStruct::*>` → `true`（const 成员变量指针）；
  - `std::is_member_object_pointer_v<void (MyClass::*)()>` → `false`（成员函数指针）；
  - `std::is_member_object_pointer_v<int*>` → `false`（普通指针，非成员变量指针）；
- **练习点**：成员变量指针类型的偏特化匹配、与成员函数指针的类型区分。

## 15. `std::enable_if<B, T = void>`

- **类别**：编译期条件类型工具（SFINAE 核心）

- **作用**：在编译期根据布尔值 B 决定是否「启用」某个类型：若 B 为 true，则暴露类型 T；若 B 为 false，则无此类型定义（触发 SFINAE，让编译器跳过当前重载 / 特化）。

- **输入**：

  - B：编译期布尔常量（如 `std::is_integral_v<T>`、`true`/`false`）；
  - T：可选的默认类型（默认值为 `void`）；

- **输出**：

  - 若 B 为 `true` → 类型 `std::enable_if_t<B, T>` 等价于 T；
  - 若 B 为 `false` → `std::enable_if_t<B, T>` 无定义（编译期匹配失败）；

- **示例**：

  - `std::enable_if_t<std::is_integral_v<int>, double>` → `double`；

  - `std::enable_if_t<false, int>` → 无定义；

  - 典型应用：限制函数模板的参数类型

    cpp

    

    运行

    

    

    

    ```
    // 仅当 T 是整数类型时，此函数重载才可用
    template <typename T>
    std::enable_if_t<std::is_integral_v<T>> print(T val) {
        std::cout << "整数：" << val << std::endl;
    }
    ```

- **练习点**：SFINAE 技巧、函数模板重载控制、类型约束。

## 16. `std::remove_cv<T>`

- **类别**：类型转换工具
- **作用**：剥离类型 T 的 const 和 volatile 限定符（单独或组合的 cv 限定符均会被移除）。
- **输入**：任意类型 T（可带 const、volatile、const volatile 限定符）。
- **输出**：
  - 若 T 是 `const U`/`volatile U`/`const volatile U` → 输出 U；
  - 若 T 无 cv 限定符 → 输出 T；
  - 注意：仅移除顶层 cv 限定符（如 `const int*` 会保留 const，因为 const 修饰的是指针指向的内容，非顶层）；
- **示例**：
  - `std::remove_cv_t<const int>` → `int`；
  - `std::remove_cv_t<volatile double>` → `double`；
  - `std::remove_cv_t<const volatile char>` → `char`；
  - `std::remove_cv_t<const int*>` → `const int*`（顶层是指针，cv 修饰的是 int，非顶层）；
  - `std::remove_cv_t<int* const>` → `int*`（顶层 const 修饰指针，被移除）；
- **练习点**：cv 限定符的偏特化匹配、顶层 / 底层 cv 的区分。

## 17. `std::add_pointer<T>`

- **类别**：类型转换工具
- **作用**：为类型 T 添加指针属性，规则等价于「取 T 去掉引用后的类型，再添加 *」。
- **输入**：任意类型 T（包括引用、函数、数组等）。
- **输出**：
  1. 先剥离 T 的引用属性（`std::remove_reference_t<T>`）；
  2. 对剥离后的类型 U，生成 `U*` 类型；
- **示例**：
  - `std::add_pointer_t<int>` → `int*`；
  - `std::add_pointer_t<int&>` → `int*`（先剥离引用）；
  - `std::add_pointer_t<void(int)>` → `void(*)(int)`（函数类型转函数指针）；
  - `std::add_pointer_t<const double&&>` → `const double*`（先剥离右值引用）；
- **练习点**：引用剥离 + 指针类型生成、函数类型转函数指针的偏特化。

## 18. `std::is_same<T, U>`

- **类别**：类型相等判断模板
- **作用**：在编译期判断两个类型 T 和 U 是否为完全相同的类型（包括 cv 限定符、引用、指针等细节）。
- **输入**：任意两个类型 T、U。
- **输出**：编译期布尔值（继承自 `std::true_type` 或 `std::false_type`）：
  - 若 T 和 U 是完全一致的类型 → `true_type`；
  - 否则 → `false_type`；
- **示例**：
  - `std::is_same_v<int, int>` → `true`；
  - `std::is_same_v<int, const int>` → `false`；
  - `std::is_same_v<int&, int>` → `false`；
  - `std::is_same_v<int*, const int*>` → `false`；
  - `std::is_same_v<std::decay_t<int&>, int>` → `true`；
- **练习点**：基础模板全特化、类型精确匹配判断。

## 19. `std::is_convertible<T, U>`

- **类别**：类型转换检查模板
- **作用**：在编译期判断类型 T 是否可以隐式转换为类型 U（遵循 C++ 隐式转换规则）。
- **输入**：任意两个类型 T、U。
- **输出**：编译期布尔值（继承自 `std::true_type` 或 `std::false_type`）：
  - 若 T 可隐式转换为 U → `true_type`；
  - 否则 → `false_type`；
- **示例**：
  - `std::is_convertible_v<int, double>` → `true`（数值类型隐式转换）；
  - `std::is_convertible_v<std::string, const char*>` → `true`（std::string 可隐式转 const char*）；
  - `std::is_convertible_v<int*, void*>` → `true`（指针向上转换）；
  - `std::is_convertible_v<double, int&>` → `false`（不能隐式转换为非 const 引用）；
  - `std::is_convertible_v<MyDerived, MyBase>` → `true`（派生类转基类）；
- **练习点**：隐式转换规则理解、SFINAE 结合类型转换检查。

## 20. `std::aligned_storage<Len, Align>`

- **类别**：内存对齐类型工具

- **作用**：生成一个大小至少为 Len 字节、对齐方式为 Align 的未初始化存储类型，用于手动管理对象的内存布局（如自定义容器、内存池）。

- **输入**：

  - Len：编译期整数常量（表示存储的最小字节数）；
  - Align：可选编译期整数常量（对齐方式，默认值为 `std::max_align_t` 的对齐要求）；

- **输出**：

  - 一个匿名的 POD 类型 `std::aligned_storage_t<Len, Align>`，满足：
    1. 大小 ≥ Len 字节；
    2. 对齐方式 ≥ Align（或默认最大对齐）；
    3. 无构造 / 析构函数，无成员变量，仅用于内存存储；

- **示例**：

  - `std::aligned_storage_t<4, 4>` → 大小 4 字节、4 字节对齐的存储类型（适配 int）；

  - `std::aligned_storage_t<sizeof(std::string), alignof(std::string)>` → 适配 std::string 的存储类型；

  - 典型应用：手动构造对象

    cpp

    

    运行

    

    

    

    ```
    // 分配内存但不构造对象
    std::aligned_storage_t<sizeof(std::string), alignof(std::string)> buf;
    // 原地构造 string
    new (&buf) std::string("hello");
    // 手动析构
    reinterpret_cast<std::string&>(buf).~basic_string();
    ```

- **练习点**：内存对齐规则、未初始化内存的对象构造 / 析构、类型大小 / 对齐推导。





# 额外附赠（和 enable_if 同级）

## 21. `std::void_t<T...>`（C++17 超级神器）

- **作用**：把任意类型列表变成 `void`
- **用途**：检测某个类型是否拥有某个成员函数 / 成员类型
- **练习点**：现代元编程核心技巧，极简但强大

它处理的对象包括：

1、普通调用对象

```
f(args...)
```

包括：

- 普通函数
- 函数指针
- lambda
- 函数对象（operator()）

2. 成员函数指针

```C++
(obj.*pmf)(args...)
//或者
(ptr->*pmf)(args...)
```

3. 成员变量指针

```C++
obj.*pmd
//或者
ptr->*pmd
```



------

# 我给你排一个**最佳练习顺序**

从易到难，你能一步步吃透：

1. `is_same`
2. `remove_reference`
3. `remove_pointer`
4. `is_void`
5. `is_pointer`
6. `is_integral`
7. `conditional`
8. `decay`
9. `is_class`
10. `invoke_result`
11. `void_t`

# 更多的STL工具实现练习

`std::is_member_function_pointer<T>`