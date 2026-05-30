/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-30 07:38:35
 * @LastEditors: gimphammer@gmail.com
 * @LastEditTime: 2026-05-30 07:41:22
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */


#ifndef MY_IS_POINTER_H
#define MY_IS_POINTER_H

#include <type_traits>

namespace mst{
template <typename T>
struct my_is_pointer : std::false_type
{};

template <typename T>
struct my_is_pointer<T*> : std::true_type
{};

template <typename T>
inline constexpr bool my_is_pointer_v = my_is_pointer<T>::value;


};


void test_my_is_pointer();


#endif //MY_IS_POINTER_H