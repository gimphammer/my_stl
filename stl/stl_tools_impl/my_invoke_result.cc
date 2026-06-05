/**
 * @Author: gimphammer
 * @Date: 2026-05-31 21:03:45
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-06-06 04:42:20
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */



#include "stl/stl_tools_impl/my_invoke_result.h"
#include <type_traits>
#include <iostream>


struct Test {
    // 成员变量
    int value = 10;
    
    // 普通成员函数
    int func(int a) { return a; }
    // const 成员函数
    int func_c(int a) const { return a; }
};

int add(int a, int b) { return a + b; }


void test_my_invoke_result()
{
  std::cout << "--start test my_invoke_result--" << "\n";
  std::cout << "testing.....\n";
  // 1. 普通函数
  static_assert(
      std::is_same_v<mst::my_invoke_result_t<decltype(&add), int, int>, int>);

  // 2. lambda
  auto lam = [](int x) { return x * 2; };
  static_assert(
      std::is_same<
          mst::my_invoke_result_t<decltype(lam), int>,
          int
      >::value
  );

  // 3. 普通成员函数
  static_assert(
      std::is_same<
          mst::my_invoke_result_t<decltype(&Test::func), Test, int>,
          int
      >::value
  );

  // 4. const 成员函数
  static_assert(
      std::is_same<
          mst::my_invoke_result_t<decltype(&Test::func_c), const Test, int>,
          int
      >::value
  );

  // 5. 成员变量指针
  static_assert(
      std::is_same<
          mst::my_invoke_result_t<decltype(&Test::value), Test&>,
          int&
      >::value
  );

  std::cout << "=============passed============" << "\n\n";
}
