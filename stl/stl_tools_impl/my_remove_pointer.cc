/**
 * @Author: gimphammer
 * @Date: 2026-05-31 17:47:02
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-05-31 18:18:08
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */



#include "stl/stl_tools_impl/my_remove_pointer.h"
#include "stl/stl_tools_impl/my_test_class.h"
#include <iostream>


void test_my_remove_pointer()
{
  std::cout << "--start test my_remove_pointer--" << "\n";
  // 测试 1：普通指针
  bool a = std::is_same_v<mst::my_remove_pointer_t<int*>, int>;
  std::cout << "int* -> int : " << a << std::endl;

  // 测试 2：二级指针
  bool b = std::is_same_v<mst::my_remove_pointer_t<int**>, int*>;
  std::cout << "int** -> int* : " << b << std::endl;

  // 测试 3：非指针
  bool c = std::is_same_v<mst::my_remove_pointer_t<int>, int>;
  std::cout << "int -> int : " << c << std::endl;

  // 测试 4：const 指针
  bool d = std::is_same_v<mst::my_remove_pointer_t<const int*>, const int>;
  std::cout << "const int* -> const int : " << d << std::endl;

  // 测试 5：void*
  bool e = std::is_same_v<mst::my_remove_pointer_t<void*>, void>;
  std::cout << "void* -> void : " << e << std::endl;

  // 测试 6：函数指针
  bool f = std::is_same_v<mst::my_remove_pointer_t<void(*)(int)>, void(int)>;
  std::cout << "函数指针 -> 函数类型 : " << f << std::endl;  
  std::cout << "==============end===============" << "\n\n";    
}