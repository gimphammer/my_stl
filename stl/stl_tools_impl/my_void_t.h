/**
 * @Author: gimphammer
 * @Date: 2026-06-06 10:39:44
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-06-06 10:44:57
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]if
 */


#ifndef MY_VOID_T_H
#define MY_VOID_T_H


namespace mst{

template <typename... Args>
struct my_void
{
  using type = void;
};

template <typename... Args>
using my_void_t = typename my_void<Args...>::type;



};

void test_my_void();

#endif //MY_VOID_T_H