/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-30 06:48:12
 * @LastEditors: gimphammer@gmail.com
 * @LastEditTime: 2026-05-30 07:30:07
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */
#include <iostream>
#include "stl/stl_tools_impl/my_is_void.h"
#include "stl/stl_tools_impl/my_test_class.h"






void test_my_is_void()
{
  std::cout << "--start test my_is_void--" << "\n";

  std::string info = mst::my_is_void_v<void> ? "void" : "not void";
  std::cout << "[Test for my_is_void] \"void\" is " << info << "\n";

  info = mst::my_is_void_v<bool> ? "void" : "not void";
  std::cout << "[Test for my_is_void] \"bool\" is " << info << "\n";

  info = mst::my_is_void_v<MyClass> ? "void" : "not void";
  std::cout << "[Test for my_is_void] \"MyClass\" is " << info << "\n";

  std::cout << "============end===========" << "\n\n";
}
