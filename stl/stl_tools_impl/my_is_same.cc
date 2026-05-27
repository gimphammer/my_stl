/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-27 09:49:50
 * @LastEditors: gimphammer@gmail.com
 * @LastEditTime: 2026-05-27 10:45:06
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */
#include "stl/stl_tools_impl/my_is_same.h"
#include <iostream>

class MISFather
{
public:
  MISFather() = default;
  virtual ~MISFather() = default;  

private:
  int member;

};


class MISSon : public MISFather
{
public:
  MISSon() = default;
  virtual ~MISSon() = default;  
};


bool test_my_is_same()
{
  bool is_same = mst::my_is_same_v<MISFather, MISSon>;
  std::string info_str = is_same ? "the same" : "different";
  std::cout << "class [MISFather] and [MISSon] is " << info_str <<  "\n";
  return is_same;
}


