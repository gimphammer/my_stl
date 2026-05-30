/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-27 09:49:50
 * @LastEditors: gimphammer@gmail.com
 * @LastEditTime: 2026-05-29 21:51:26
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


using MISSonAlias = MISSon;

bool test_my_is_same()
{
  std::cout << "--start test my_is_same--" << "\n";
  bool is_same = mst::my_is_same_v<MISFather, MISSon>;
  std::string info_str = is_same ? "the same" : "different";
  std::cout << "class [MISFather] and [MISSon] is " << info_str <<  "\n";

  is_same = mst::my_is_same_v<MISSonAlias, MISSon>;
  info_str = is_same ? "the same" : "different";
  std::cout << "class [MISSonAlias] and [MISSon] is " << info_str <<  "\n";

  std::cout << "============end===========" << "\n\n";

  return is_same;
}


