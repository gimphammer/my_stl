/**
 * @Author: gimphammer
 * @Date: 2026-06-06 04:44:14
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-06-06 09:01:02
 * @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
 * @Description: [None]
 */


//This is only for practising again
//mir is for my_invoke_result

#include <utility>
#include <type_traits>

namespace mir{
/**
 * There are three kind of input of invoke_result:
 * 1. basic: something like common function pointer
 *    all these has the same invoke form:
 *         common-function, Lambda, Functor, static member function
 * 2. member function pointer
 *    2.1 member function pointer + obj
 *    2.2 member function pointer + obj-pointer
 * 3. member pointer
 *    3.1 member pointer + obj
 *    3.2 member pointer + obj-pointer
 */


//TODO: three invoke "template function"

//1. basic
template <typename F, typename... Args>
auto mi(F&& fp_or_obj, Args&&... args) 
    -> decltype(std::forward<F>(fp_or_obj)(std::forward<Args>(args)...))
{
  
  return std::forward<F>(fp_or_obj)(std::forward<Args>(args)...);
}

//2. member function pointer
//  2.1 member function pointer + obj
template <typename MemFn, typename Obj, typename... Args,
          typename = std::enable_if_t<
                            std::is_member_function_pointer_v<std::decay_t<MemFn>>>>
auto mi(MemFn&& mem_fn, Obj&& obj, Args&&... args)
    -> decltype((std::forward<Obj>(obj).*mem_fn)(std::forward<Args>(args)...))
{
  
  return (std::forward<Obj>(obj).*mem_fn)
         (std::forward<Args>(args)...);
}

//  2.2 member function pointer + obj-pointer
template <typename MemFn, typename ObjPointer, typename... Args,
          typename = std::enable_if_t<
                        std::is_member_function_pointer_v<std::decay_t<MemFn>>>>
auto mi(MemFn&& mem_fn, ObjPointer* obj_p, Args&&... args)
    -> decltype((obj_p->*mem_fn)(std::forward<Args>(args)...))
{
  return (obj_p->*mem_fn)(std::forward<Args>(args)...);
}


//3. member pointer
//  3.1 member pointer + obj
template <typename MemPointer, typename Obj,
          typename = std::enable_if_t<
                          std::is_member_object_pointer_v<std::decay_t<MemPointer>>>>
auto mi(MemPointer&& p_mem, Obj&& obj)
    -> decltype(std::forward<Obj>(obj).*p_mem)
{
  return std::forward<Obj>(obj).*p_mem;
}

//  3.2 member pointer + obj-pointer
template <typename MemPointer, typename Obj,
          typename = std::enable_if_t<
                          std::is_member_object_pointer_v<std::decay_t<MemPointer>>>>
auto mi(MemPointer&& p_mem, Obj* p_obj)
    -> decltype(p_obj->*p_mem)
{
  return p_obj->*p_mem;
}

//mir_impl<Pointer p, Args... args>
template <typename , typename F, typename... Args>
struct mir_impl
{
};

template <typename F, typename... Args>
struct mir_impl<
            std::void_t<decltype(mi(std::declval<F>(), std::declval<Args>()...))>,
            F, 
            Args...>
{
  using type = decltype(mi(std::declval<F>(), std::declval<Args>()...));
};


//TODO: "struct mir_impl" to encapsulating invoke

template <typename T, typename... Args>
struct mir : mir_impl<void, T, Args...>
{
};

//TODO: "using def" mir_t, my_invoke_reuslt_t
template <typename T, typename... Args>
using mir_t = typename mir<T, Args...>::type;


};


void test_mir();
