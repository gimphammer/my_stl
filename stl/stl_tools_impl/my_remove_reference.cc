/**
 * @Author: gimphammer
 * @Date: 2026-05-31 18:21:34
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-05-31 18:40:41
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */



#include "stl/stl_tools_impl/my_remove_reference.h"
#include <iostream>
#include <type_traits>

void test_my_remove_reference()
{
  std::cout << "--start test my_remove_reference--" << "\n";

  std::string info = std::is_same_v<mst::my_remove_reference_t<int&>, int>
                      ? "successed" : "failed";
  std::cout << "int& -> int : operation " << info << std::endl;

  info = std::is_same_v<mst::my_remove_reference_t<int&&>, int>
                      ? "successed" : "failed";
  std::cout << "int&& -> int : operation " << info << std::endl;

  info = std::is_same_v<mst::my_remove_reference_t<int>, int>
                      ? "successed" : "failed";
  std::cout << "int -> int : operation " << info << std::endl;
  
  info = std::is_same_v<mst::my_remove_reference_t<const int&>, const int>
                      ? "successed" : "failed";
  std::cout << "const int& -> const int : operation " << info << std::endl;

  info = std::is_same_v<mst::my_remove_reference_t<const int&&>, const int>
                      ? "successed" : "failed";
  std::cout << "const int&& -> const int : operation " << info << std::endl;
  
  info = std::is_same_v<mst::my_remove_reference_t<int*&>, int*>
                      ? "successed" : "failed";
  std::cout << "int*& -> int* : operation " << info << std::endl;

  info = std::is_same_v<mst::my_remove_reference_t<int*&&>, int*>
                      ? "successed" : "failed";
  std::cout << "int*&& -> int* : operation " << info << std::endl;

  std::cout << "================end===============" << "\n\n";  

}
