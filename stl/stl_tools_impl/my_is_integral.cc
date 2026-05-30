/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-30 07:09:50
 * @LastEditors: gimphammer@gmail.com
 * @LastEditTime: 2026-05-30 07:37:45
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */




#include "stl/stl_tools_impl/my_is_integral.h"
#include "stl/stl_tools_impl/my_test_class.h"
#include <type_traits>
#include <iostream>

void test_my_is_integral()
{
  std::cout << "--start test my_is_integral--" << "\n";

  std::string info = mst::my_is_integral_v<MyClass> ? "true" : "false";
  std::string res_from_std = std::is_integral_v<MyClass> ? "true" : "false";
  std::cout << "[Test for my_is_integral] \"MyClass\" is: " << info 
            << ", res from std::is_integral_v: " << res_from_std << "\n";


  info = mst::my_is_integral_v<void> ? "true" : "false";
  res_from_std = std::is_integral_v<void> ? "true" : "false";
  std::cout << "[Test for my_is_integral] \"void\" is: " << info 
            << ", res from std::is_integral_v: " << res_from_std << "\n";

  ///////////////////
  info = mst::my_is_integral_v<bool> ? "true" : "false";
  res_from_std = std::is_integral_v<bool> ? "true" : "false";
  std::cout << "[Test for my_is_integral] \"bool\" is: " << info 
            << ", res from std::is_integral_v: " << res_from_std << "\n";

  info = mst::my_is_integral_v<char> ? "true" : "false";
  res_from_std = std::is_integral_v<char> ? "true" : "false";
  std::cout << "[Test for my_is_integral] \"char\" is: " << info 
            << ", res from std::is_integral_v: " << res_from_std << "\n";

  info = mst::my_is_integral_v<signed char> ? "true" : "false";
  res_from_std = std::is_integral_v<signed char> ? "true" : "false";
  std::cout << "[Test for my_is_integral] \"signed char\" is: " << info 
            << ", res from std::is_integral_v: " << res_from_std << "\n";

  info = mst::my_is_integral_v<unsigned char> 
                          ? "true" : "false";
  res_from_std = std::is_integral_v<unsigned char> ? "true" : "false";                          
  std::cout << "[Test for my_is_integral] \"unsigned char\" is: " << info 
            << ", res from std::is_integral_v: " << res_from_std << "\n";

  info = mst::my_is_integral_v<short> ? "true" : "false";
  res_from_std = std::is_integral_v<short> ? "true" : "false";  
  std::cout << "[Test for my_is_integral] \"short\" is: " << info 
            << ", res from std::is_integral_v: " << res_from_std << "\n";
  

  info = mst::my_is_integral_v<unsigned short> ? "true" : "false";
  res_from_std = std::is_integral_v<unsigned short> ? "true" : "false";  
  std::cout << "[Test for my_is_integral] \"unsigned short\" is: " << info
            << ", res from std::is_integral_v: " << res_from_std << "\n";

  info = mst::my_is_integral_v<int> ? "true" : "false";
  res_from_std = std::is_integral_v<int> ? "true" : "false";  
  std::cout << "[Test for my_is_integral] \"int\" is: " << info
            << ", res from std::is_integral_v: " << res_from_std << "\n";;
  

  info = mst::my_is_integral_v<unsigned int> ? "true" : "false";
  res_from_std = std::is_integral_v<unsigned int> ? "true" : "false";
  std::cout << "[Test for my_is_integral] \"unsigned int\" is: " << info
            << ", res from std::is_integral_v: " << res_from_std << "\n";

  info = mst::my_is_integral_v<long> ? "true" : "false";
  res_from_std = std::is_integral_v<long> ? "true" : "false";
  std::cout << "[Test for my_is_integral] \"long\" is: " << info
            << ", res from std::is_integral_v: " << res_from_std << "\n";

  info = mst::my_is_integral_v<unsigned long> ? "true" : "false";
  res_from_std = std::is_integral_v<unsigned long> ? "true" : "false";
  std::cout << "[Test for my_is_integral] \"unsigned long\" is: " << info
            << ", res from std::is_integral_v: " << res_from_std << "\n";

  info = mst::my_is_integral_v<long long> ? "true" : "false";
  res_from_std = std::is_integral_v<long long> ? "true" : "false";
  std::cout << "[Test for my_is_integral] \"long long\" is: " << info
            << ", res from std::is_integral_v: " << res_from_std << "\n"; 
  
  info = mst::my_is_integral_v<unsigned long long> ? "true" : "false";
  res_from_std = std::is_integral_v<unsigned long long> ? "true" : "false";
  std::cout << "[Test for my_is_integral] \"unsigned long long\" is: " << info
            << ", res from std::is_integral_v: " << res_from_std << "\n";

  std::cout << "=============end============" << "\n\n";
}