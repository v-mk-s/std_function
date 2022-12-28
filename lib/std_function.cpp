#include "std_function.h"

#include <type_traits>
#include <utility>
#include <stdexcept>

template <typename... Args>
class function;

#include <functional>
#include <iostream>

template <typename R, typename... Args>
function<R(Args...)>::~function()
{
    if (m_delete)
        m_delete(*this);
}

template <typename R, typename... Args>
R function<R(Args...)>:: operator()(Args... args) const
{
    if (!m_functor || !m_invoke)
        throw std::runtime_error("call an empty function object");
    return (*m_invoke)(*this, static_cast<Args>(args)...);
}

void Foo::print_add(int i) const { std::cout << num_ + i << '\n'; };

void print_num(int i)
{
    std::cout << i << '\n';
}

void PrintNum::operator()(int i) const
{
    std::cout << i << '\n';
}