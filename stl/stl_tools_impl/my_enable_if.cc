/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-27 18:32:58
 * @LastEditors: gimphammer@gmail.com
 * @LastEditTime: 2026-05-29 21:50:19
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */
#include "stl/stl_tools_impl/my_enable_if.h"


#include <iostream>


void test_my_enable_if()
{
  std::cout << "--start test my_enable_if--" << "\n";
  test_mei_template_param_pos(1.3);
  test_mei_template_param_pos(5);
  test_mei_func_param_pos(1.3);
  test_mei_func_param_pos(5);
  test_mei_return_pos(1.3);
  test_mei_return_pos(5);
  std::cout << "============end============" << "\n\n";
}