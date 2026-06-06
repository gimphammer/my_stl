/**
 * @Author: gimphammer
 * @Date: 2026-06-06 04:44:19
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-06-06 09:02:37
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */




#include "stl/stl_tools_impl/mir.h"
#include <type_traits>
#include <iostream>


struct MirTest {
    // 成员变量
    int value = 10;
    
    // 普通成员函数
    int func(int a) { return a; }
    // const 成员函数
    int func_c(int a) const { return a; }
};

int mir_add(int a, int b) { return a + b; }


void test_mir()
{
  std::cout << "--start test mir--" << "\n";
  std::cout << "testing.....\n";
  // 1. 普通函数
  static_assert(
      std::is_same_v<mir::mir_t<decltype(&mir_add), int, int>, int>);

  // 2. lambda
  auto lam = [](int x) { return x * 2; };
  static_assert(
      std::is_same_v<
          mir::mir_t<decltype(lam), int>, int>
  );

  // 3. 普通成员函数
  static_assert(
      std::is_same_v<
          mir::mir_t<decltype(&MirTest::func), MirTest, int>, int>
  );

  // 4. const 成员函数
  static_assert(
      std::is_same_v<
          mir::mir_t<decltype(&MirTest::func_c), const MirTest, int>, int>
  );

  // 5. 成员变量指针
  static_assert(
      std::is_same_v<
          mir::mir_t<decltype(&MirTest::value), MirTest&>, int&>
  );

  std::cout << "=============passed============" << "\n\n";
}
