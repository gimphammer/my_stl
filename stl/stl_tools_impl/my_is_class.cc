/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-31 12:51:29
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-05-31 18:31:02
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */

#include "stl/stl_tools_impl/my_is_class.h"
#include "stl/stl_tools_impl/my_test_class.h"
#include <iostream>

void test_my_is_class()
{
  std::cout << "--start test my_is_class--" << "\n";

  std::string info = mst::my_is_class_v<bool> ? "true" : "false";
  std::string res_from_std = std::is_class_v<bool> ? "true" : "false";
  std::cout << "[Test for my_is_class] \"bool\" is " << info
            << ", res from std::is_pointer: " << res_from_std << "\n";  


  info = mst::my_is_class_v<MyClass> ? "true" : "false";
  res_from_std = std::is_class_v<MyClass> ? "true" : "false";
  std::cout << "[Test for my_is_class] \"MyClass\" is " << info
            << ", res from std::is_pointer: " << res_from_std << "\n";

            
  std::cout << "============end============" << "\n\n";  
}