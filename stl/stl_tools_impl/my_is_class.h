/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-31 12:51:27
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-05-31 15:26:01
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */


#ifndef MY_IS_CLASS_H
#define MY_IS_CLASS_H


#include <type_traits>


namespace mst{

// // 手写 is_class 核心实现
// template <typename T>
// struct my_is_class
// {
// private:
//     // 技巧：用 &T::x 测试是否是类
//     template <typename U>
//     static std::true_type test(decltype(static_cast<void (U::*)()>(nullptr))*);

//     // 兜底：所有不满足的情况
//     template <typename U>
//     static std::false_type test(...);

// public:
//     static constexpr bool value = decltype(test<T>(nullptr))::value;
// };

// // C++17 便捷变量模板
// template <typename T>
// constexpr bool my_is_class_v = my_is_class<T>::value;



// template<typename T>
// struct my_is_class
// {
// private:
//     template<typename U>
//     static char test(int U::*);

//     template<typename U>
//     static int test(...);

// public:
//     static constexpr bool value =
//         sizeof(test<T>(nullptr)) == sizeof(char);
// };


template <typename T>
struct my_is_class
{
private:
  template <typename U>  
  // static std::true_type test(decltype(static_cast<U::*>(nullptr))*);
  static std::true_type test(decltype(static_cast<void (U::*)()>(nullptr))*);

  template <typename U>
  static std::false_type test(...);

public:
  static constexpr bool value = decltype(test<T>(nullptr))::value;
};




template <typename T>
constexpr bool my_is_class_v = my_is_class<T>::value;




};

void test_my_is_class();


#endif //MY_IS_CLASS_H


