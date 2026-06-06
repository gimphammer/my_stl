/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-26 21:13:23
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-06-06 09:00:26
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */

#include <iostream>
#include "stl/stl_tools_impl/my_enable_if.h"
#include "stl/stl_tools_impl/my_is_same.h"
#include "stl/stl_tools_impl/my_is_void.h"
#include "stl/stl_tools_impl/my_is_integral.h"
#include "stl/stl_tools_impl/my_is_pointer.h"
#include "stl/stl_tools_impl/my_is_class.h"
#include "stl/stl_tools_impl/my_remove_pointer.h"
#include "stl/stl_tools_impl/my_remove_reference.h"
#include "stl/stl_tools_impl/my_conditional.h"
#include "stl/stl_tools_impl/my_invoke_result.h"
#include "stl/stl_tools_impl/mir.h"

int main(int argc, const char * argv[]) {
  // insert code here...
  
  test_my_is_same();
  test_my_enable_if();
  test_my_is_void();
  test_my_is_integral();
  test_my_is_pointer();
  test_my_is_class();
  test_my_remove_pointer();
  test_my_remove_reference();
  test_my_conditional();
  test_my_invoke_result();
  test_mir();
  return EXIT_SUCCESS;
}
