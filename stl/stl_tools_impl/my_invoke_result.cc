/**
 * @Author: gimphammer
 * @Date: 2026-05-31 21:03:45
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-06-05 20:00:34
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */



#include "stl/stl_tools_impl/my_invoke_result.h"
#include <type_traits>
struct Test {
    // 成员变量
    int value = 10;
    
    // 普通成员函数
    int func(int a) { return a; }
    // const 成员函数
    int func_c(int a) const { return a; }
};

int add(int a, int b) { return a + b; }


void test_my_invoke_result()
{
    static_assert(
        std::is_same_v<my_invoke_result_t<decltype(&add), int, int>, int>);

}
