/**
 * @Author: gimphammer
 * @Date: 2026-06-06 10:51:50
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-06-06 10:54:24
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */


#ifndef MY_IS_MEMBER_FUNCTION_POINTER_H
#define MY_IS_MEMBER_FUNCTION_POINTER_H

#include <type_traits>

namespace mst{

template <typename T>
struct my_is_member_function_pointer : std::false_type
{
};  

template <typename T>
struct my_is_member_function_pointer : std::true_type
{
};

  
};



#endif //MY_MEMBER_FUNCTION_POINTER_H
