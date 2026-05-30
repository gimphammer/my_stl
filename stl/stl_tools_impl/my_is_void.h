/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-29 21:42:49
 * @LastEditors: gimphammer@gmail.com
 * @LastEditTime: 2026-05-30 07:08:55
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */
#ifndef MY_IS_VOID_H
#define MY_IS_VOID_H

#include <type_traits>

namespace mst{

template <typename T>
struct my_is_void : std::false_type
{};

template <> //全特化，就不需要再写typename了
struct my_is_void<void> : std::true_type
{};

template <typename T>
inline constexpr bool my_is_void_v = my_is_void<T>::value;

}

void test_my_is_void();

#endif //MY_IS_VOID_H