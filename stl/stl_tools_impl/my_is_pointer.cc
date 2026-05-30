/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-30 07:38:37
 * @LastEditors: gimphammer@gmail.com
 * @LastEditTime: 2026-05-30 08:28:33
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */




#include "stl/stl_tools_impl/my_is_pointer.h"
#include "stl/stl_tools_impl/my_test_class.h"
#include <iostream>


void test_my_is_pointer()
{
  std::cout << "--start test my_is_poiner--" << "\n";
  
  std::string info = mst::my_is_pointer_v<bool> ? "true" : "false";
  std::string res_from_std = std::is_pointer_v<bool> ? "true" : "false";
  std::cout << "[Test for my_is_pointer] \"bool\" is " << info
            << ", res from std::is_pointer: " << res_from_std << "\n";

  info = mst::my_is_pointer_v<bool*> ? "true" : "false";
  res_from_std = std::is_pointer_v<bool*> ? "true" : "false";
  std::cout << "[Test for my_is_pointer] \"bool*\" is " << info
            << ", res from std::is_pointer: " << res_from_std << "\n";

  info = mst::my_is_pointer_v<MyClass*> ? "true" : "false";
  res_from_std = std::is_pointer_v<MyClass*> ? "true" : "false";
  std::cout << "[Test for my_is_pointer] \"MyClass*\" is " << info
            << ", res from std::is_pointer: " << res_from_std << "\n";

  std::cout << "============end============" << "\n\n";  
}


