/**
 * @Author: gimphammer
 * @Date: 2026-05-31 17:46:59
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-05-31 18:14:08
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */



#ifndef MY_REMOVE_POINTER_H
#define MY_REMOVE_POINTER_H

#include <type_traits>

namespace mst{

template <typename T>
struct my_remove_pointer
{
  using type = T;
};

template <typename T>
struct my_remove_pointer<T*>
{
  using type = T;
};

template <typename T>
using my_remove_pointer_t = typename my_remove_pointer<T>::type;


};

void test_my_remove_pointer();


#endif //MY_REMOVE_POINTER_H


