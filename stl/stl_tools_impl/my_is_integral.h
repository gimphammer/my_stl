/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-30 07:09:48
 * @LastEditors: gimphammer@gmail.com
 * @LastEditTime: 2026-05-30 07:24:12
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */


#ifndef MY_IS_INTEGRAL_H
#define MY_IS_INTEGRAL_H

#include <type_traits>


namespace mst {

template <typename T>
struct my_is_integal : std::false_type{};

template <> struct my_is_integal<bool> : std::true_type{};
template <> struct my_is_integal<char> : std::true_type{};
template <> struct my_is_integal<signed char> : std::true_type{};
template <> struct my_is_integal<unsigned char> : std::true_type{};
template <> struct my_is_integal<short> : std::true_type{};
template <> struct my_is_integal<unsigned short> : std::true_type{};
template <> struct my_is_integal<int> : std::true_type{};
template <> struct my_is_integal<unsigned int> : std::true_type{};
template <> struct my_is_integal<long> : std::true_type{};
template <> struct my_is_integal<unsigned long> : std::true_type{};
template <> struct my_is_integal<long long> : std::true_type{};
template <> struct my_is_integal<unsigned long long> : std::true_type{};

template <typename T>
inline constexpr bool my_is_integral_v = my_is_integal<T>::value;


};


void test_my_is_integral();

#endif //MY_IS_INTEGRAL_H


