/**
 * @Author: gimphammer
 * @Date: 2026-06-06 10:39:45
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-06-06 10:48:50
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */


#include "stl/stl_tools_impl/my_void_t.h"
#include <iostream>
#include <type_traits>



void test_my_void()
{
  std::cout << "--start test my_void--" << std::endl;
  std::cout << "testing static_assert....\n";
  static_assert(
    std::is_same_v<mst::my_void_t<int>, void>
  );

  static_assert(
    std::is_same_v<mst::my_void_t<double, int>, void>
  );


  static_assert(
    std::is_same_v<mst::my_void_t<double, int*>, void>
  );  
  std::cout << "=========end==========" << "\n\n";

  
}

