/**
 * @Author: gimphammer@gmail.com
 * @Date: 2026-05-27 02:10:17
 * @LastEditors: gimphammer@gmail.com
 * @LastEditTime: 2026-05-27 11:07:58
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */
#ifndef MY_IS_SAME_H
#define MY_IS_SAME_H

#include <type_traits>


namespace mst {

template<typename T, typename U>
struct my_is_same : std::false_type{
  // bool same = std::is_same<T, U>::value;
};

template<typename T>
struct my_is_same<T, T> : std::true_type{ 
};


// template<typename T, typename U>
// using my_is_same_v = my_is_same<T, U>::value;


template<typename T, typename U>
inline constexpr bool my_is_same_v = my_is_same<T, U>::value;


}

bool test_my_is_same();



#endif //MY_IS_SAME_H