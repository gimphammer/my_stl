```c++
#include <type_traits>
#include <utility>

namespace mst
{

//--------------------------------------------------
// invoke
//--------------------------------------------------

template<typename F, typename... Args>
auto invoke(F&& f, Args&&... args)
    -> decltype(std::forward<F>(f)(std::forward<Args>(args)...))
{
    return std::forward<F>(f)(std::forward<Args>(args)...);
}

//--------------------------------------------------
// 成员函数指针
//--------------------------------------------------

template<
    typename MemFn,
    typename Obj,
    typename... Args,
    typename = std::enable_if_t<
        std::is_member_function_pointer_v<std::decay_t<MemFn>>>>
auto invoke(MemFn&& fn, Obj&& obj, Args&&... args)
    -> decltype(
        (std::forward<Obj>(obj).*fn)
        (std::forward<Args>(args)...))
{
    return
        (std::forward<Obj>(obj).*fn)
        (std::forward<Args>(args)...);
}

template<
    typename MemFn,
    typename Ptr,
    typename... Args,
    typename = std::enable_if_t<
        std::is_member_function_pointer_v<std::decay_t<MemFn>>>>
auto invoke(MemFn&& fn, Ptr* ptr, Args&&... args)
    -> decltype(
        (ptr->*fn)
        (std::forward<Args>(args)...)
    )
{
    return
        (ptr->*fn)
        (std::forward<Args>(args)...);
}

//--------------------------------------------------
// 成员变量指针
//--------------------------------------------------

template<
    typename MemObj,
    typename Obj,
    typename = std::enable_if_t<
        std::is_member_object_pointer_v<std::decay_t<MemObj>>>>
auto invoke(MemObj&& member, Obj&& obj)
    -> decltype(std::forward<Obj>(obj).*member)
{
    return std::forward<Obj>(obj).*member;
}

template<
    typename MemObj,
    typename Ptr,
    typename = std::enable_if_t<
        std::is_member_object_pointer_v<std::decay_t<MemObj>>>>
auto invoke(MemObj&& member, Ptr* ptr)
    -> decltype(ptr->*member)
{
    return ptr->*member;
}

//--------------------------------------------------
// invoke_result
//--------------------------------------------------

template<typename, typename F, typename... Args>
struct invoke_result_impl
{
};

template<typename F, typename... Args>
struct invoke_result_impl<
    std::void_t<decltype(mst::invoke(
      												std::declval<F>(),
							                std::declval<Args>()...))>,
    F,
    Args...>
{
    using type = decltype(mst::invoke(
					            		    std::declval<F>(),
          						      	std::declval<Args>()...));
};

template<typename F, typename... Args>
struct invoke_result
    : invoke_result_impl<void, F, Args...>
{
};

template<typename F, typename... Args>
using invoke_result_t = typename invoke_result<F, Args...>::type;

}
```

