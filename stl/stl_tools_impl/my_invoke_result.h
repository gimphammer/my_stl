/**
* @Author: gimphammer
* @Date: 2026-05-31 21:03:44
 * @LastEditors: gimphammer
 * @LastEditTime: 2026-06-06 04:41:54
* @Copyright: Copyright (c) 2026 by gimphammer@gmail.com, All rights reserved.
* @Description: [None]
*/



#ifndef MY_INVOKE_RESULT_H
#define MY_INVOKE_RESULT_H

#include <utility>
#include <type_traits>
////////////definition of invoke
// 1. callable
//    suitable for common-function, Lambda, Functor, static member function
//    and conmon-funtion-pointer
// 2. member function pointer   --> A::*
// 3. member variable pointer   --> A::*
//  

namespace mst{




//1.common callable 
template <typename F, typename... Args>
auto my_invoke(F&& f, Args&&... args) -> 
    decltype(std::forward<F>(f)(std::forward<Args>(args)...))
{
  return std::forward<F>(f)(std::forward<Args>(args)...);
}


//2. member function pointer
//2.1  member function pointer with obj
// form like: A::*
// form of invoke:  (A::*)(args...)
// form of invoke:  C(A::*)(args...)
template <typename MemFn, typename Obj, typename... Args,
          typename = std::enable_if_t<
                std::is_member_function_pointer_v<std::decay_t<MemFn>>>>
auto my_invoke(MemFn&& f, Obj&& obj, Args&&... args)  
     -> decltype((std::forward<Obj>(obj).*f)(std::forward<Args>(args)...))
{
  return (std::forward<Obj>(obj).*f)
         (std::forward<Args>(args)...);
}

//2.1  member funtion pointer with obj pointer
template <typename MemFn, typename ObjPtr, typename... Args,
          typename = std::enable_if_t<
                std::is_member_function_pointer_v<std::decay_t<MemFn>>>>
auto my_invoke(MemFn&& f, ObjPtr* ptr, Args&&... args) 
      -> decltype((ptr->*f)(std::forward<Args>(args)...))
{
  return (ptr->*f)(std::forward<Args>(args)...);
}


//2. member variable pointer
//2.1 mem-var pointer with obj
template <typename MemPtr, typename Obj,
          typename = std::enable_if_t<
                      std::is_member_object_pointer_v<std::decay_t<MemPtr>>>>
auto my_invoke(MemPtr&& member_ptr, Obj&& obj) 
    -> decltype(std::forward<Obj>(obj).*member_ptr)
{
  return std::forward<Obj>(obj).*member_ptr;
}



//2.2 mem-var pointer with obj-pointer
template <typename MemPtr, typename ObjPtr,
          typename = std::enable_if_t<
                      std::is_member_object_pointer_v<std::decay_t<MemPtr>>>>
auto my_invoke(MemPtr&& mem_ptr, ObjPtr* obj_ptr)
          -> decltype(obj_ptr->*mem_ptr)
{
  return obj_ptr->*mem_ptr;
}


template <typename, typename F, typename... Args>
struct my_invoke_result_impl
{
};


template <typename F, typename... Args>
struct my_invoke_result_impl<
          std::void_t<decltype(my_invoke(std::declval<F>(), std::declval<Args>()...))>,
          F,
          Args...>
{
  using type = decltype(my_invoke(std::declval<F>(),
                                  std::declval<Args>()...));
};


template <typename T, typename... Args>
struct my_invoke_result : my_invoke_result_impl<void, T, Args...>
{
};

template <typename T, typename... Args>
using my_invoke_result_t = typename my_invoke_result<T, Args...>::type;
};

void test_my_invoke_result();

#endif //MY_INVOKE_RESULT_H


