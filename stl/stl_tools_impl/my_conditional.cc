/**
 * @Author: gimphammer
 * @Date: 2026-05-31 18:54:18
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-05-31 19:01:15
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */


#include "stl/stl_tools_impl/my_conditional.h"
#include <iostream>
#include <type_traits>

void test_my_conditional()
{

    std::cout << "--start test my_conditional--" << std::endl;

    // 1. true 选择 int
    bool b1 = std::is_same_v<mst::my_conditional_t<true, int, double>, int>;
    std::cout << "true -> int : " << (b1 ? "successed" : "failed") << std::endl;

    // 2. false 选择 double
    bool b2 = std::is_same_v<mst::my_conditional_t<false, int, double>, double>;
    std::cout << "false -> double : " << (b2 ? "successed" : "failed") << std::endl;

    // 3. true 选择 int&
    bool b3 = std::is_same_v<mst::my_conditional_t<true, int&, int&&>, int&>;
    std::cout << "true -> int& : " << (b3 ? "successed" : "failed") << std::endl;

    // 4. false 选择 int&&
    bool b4 = std::is_same_v<mst::my_conditional_t<false, int&, int&&>, int&&>;
    std::cout << "false -> int&& : " << (b4 ? "successed" : "failed") << std::endl;

    // 5. true 选择 const int
    bool b5 = std::is_same_v<mst::my_conditional_t<true, const int, int>, const int>;
    std::cout << "true -> const int : " << (b5 ? "successed" : "failed") << std::endl;

    // 6. true 选择 int*
    bool b6 = std::is_same_v<mst::my_conditional_t<true, int*, void*>, int*>;
    std::cout << "true -> int* : " << (b6 ? "successed" : "failed") << std::endl;

    std::cout << "==============end============" << "\n\n";

}