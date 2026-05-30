/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-26 21:14:15
 * @LastEditors: gimphammer@gmail.com
 * @LastEditTime: 2026-05-29 21:34:05
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */
#ifndef TEMPLATE_EXPERIMENT_H
#define TEMPLATE_EXPERIMENT_H

#include <type_traits>
#include <iostream>

namespace mst{


template<bool N, typename T>
struct my_enable_if{};

template<typename T>
struct my_enable_if<true, T>
{
  using type = T;
  // T a = std::enable_if<true, T>;  
};

template<bool ok, typename T>
using my_enable_if_t = typename my_enable_if<ok, T>::type;

}


//for test
// #include <iostream>
// template <typename T>
// void test_func(T number){
//   std::cout << "not intergal inputed: " << number;
// }


// template<typename T>
// my_enable_if_t<std::is_floating_point_v<T>, void>
// printNumber(T num) {
//     std::cout << "浮点数：" << num << "\n";
// }


// template <typename T>
// void test_func(my_enable_if_t<std::is_integral_v<T>, T> number) {
//   std::cout << "intergal inputed: " << number;
// }


//enable_if 可以用在三个地方：
//1、模板参数位置
//2、函数参数位置
//3、函数返回值位置


//Mode-1: 模版参数位置
template <typename T,
         mst::my_enable_if_t<!std::is_integral_v<T>, T>* = nullptr> 
void test_mei_template_param_pos(T number) {
 std::cout << "[Test for my_enable_if, Template Param Mode]: is not integeral "
            << number << "\n";

}

template <typename T,
         mst::my_enable_if_t<std::is_integral_v<T>, T>* = nullptr>
void test_mei_template_param_pos(T number) {
   std::cout << "[Test for my_enable_if, Template Param Mode]: is integeral "
            << number << "\n";
}

//Mode-2 函数参数位置
template <typename T>
void test_mei_func_param_pos(T number,
            mst::my_enable_if_t<!std::is_integral_v<T>,T>*  = nullptr)
{
   std::cout << "[Test for my_enable_if, Func Param Mode]: is not integeral "
            << number << "\n";
}


template <typename T>
void test_mei_func_param_pos(T number,
            mst::my_enable_if_t<std::is_integral_v<T>,T>*  = nullptr)
{
   std::cout << "[Test for my_enable_if, Func Param Mode]: is integeral "
            << number << "\n";
}

//Mode-3 函数返回值位置
//函数返回值位置：
//   虽然也可以实现功能，但这不是一种好的编码实践。
//   一般都放在“模板参数为主”，或者“函数参数位置”
template <typename T>
mst::my_enable_if_t<!std::is_integral_v<T>,T>*
test_mei_return_pos(T number)
{
   std::cout << "[Test for my_enable_if, Return Param Mode]: is not integeral "
            << number << "\n";
   T* p = nullptr;
   return p;           
}

template <typename T>
mst::my_enable_if_t<std::is_integral_v<T>,T>*
test_mei_return_pos(T number)
{
   std::cout << "[Test for my_enable_if, Return Param Mode]: is integeral "
            << number << "\n";
   T* p = nullptr;
   return p;
}


void test_my_enable_if();

#endif //TEMPLATE_EXPERIMENT_H



