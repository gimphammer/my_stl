/**
 * @Author: gimphammer
 * @Date: 2026-05-31 18:54:12
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-05-31 18:58:28
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */


#ifndef MY_CONDITIONAL_H
#define MY_CONDITIONAL_H


namespace mst{

template <bool B, typename T, typename F>
struct my_conditional{};

template <typename T, typename F>
struct my_conditional<true, T, F>{
  using type = T;
};

template <typename T, typename F>
struct my_conditional<false, T, F>{
  using type = F;
};

template <bool B, typename T, typename F>
using my_conditional_t = typename my_conditional<B, T, F>::type;


};

void test_my_conditional();


#endif //MY_CONDITIONAL_H


