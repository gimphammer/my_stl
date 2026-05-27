/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-26 21:14:15
 * @LastEditors: gimphammer@gmail.com
 * @LastEditTime: 2026-05-26 21:23:29
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */
#ifndef TEMPLATE_EXPERIMENT_H
#define TEMPLATE_EXPERIMENT_H



template<bool N, typename T>
struct my_enable_if{};

template<typename T>
struct my_enable_if<true, T>
{
  using type = T;
  // T a = std::enable_if<true, T>;  
};

// using my_enable_if_t<typename T> = my_enable_if<T>::type

// using my_enable_if_t = typename my_enable_if<T>

template<bool ok, typename T>
using my_enable_if_t = typename my_enable_if<ok, T>::type;


#endif //TEMPLATE_EXPERIMENT_H