/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-26 21:13:23
 * @LastEditors: gimphammer@gmail.com
 * @LastEditTime: 2026-05-30 07:54:38
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */

#include <iostream>
#include "stl/stl_tools_impl/my_enable_if.h"
#include "stl/stl_tools_impl/my_is_same.h"
#include "stl/stl_tools_impl/my_is_void.h"
#include "stl/stl_tools_impl/my_is_integral.h"
#include "stl/stl_tools_impl/my_is_pointer.h"


int main(int argc, const char * argv[]) {
  // insert code here...
  
  test_my_is_same();
  test_my_enable_if();
  test_my_is_void();
  test_my_is_integral();
  test_my_is_pointer();
  return EXIT_SUCCESS;
}
