/**
 * @Author: gimphammer
 * @Date: 2026-05-31 18:21:33
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-05-31 18:40:52
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */


#ifndef MY_REMOVE_REFERENCE_H
#define MY_REMOVE_REFERENCE_H


namespace mst{

template <typename T>
struct my_remove_reference{
  using type = T;
};

template <typename T>
struct my_remove_reference<T&>{
  using type = T;
};

template <typename T>
struct my_remove_reference<T&&>{
  using type = T;
};

template <typename T>
using my_remove_reference_t = typename my_remove_reference<T>::type;

};

void test_my_remove_reference();



#endif //MY_REMOVE_REFERENCE_H


