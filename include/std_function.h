// g++ -std=c++20 std_function.cpp -o std_function && ./std_function
#pragma once

#include <functional>
#include <iostream>

#include <type_traits>
#include <utility>
#include <stdexcept>

struct Foo
{
    Foo(int num) : num_(num) {}
    void print_add(int i) const;
    int num_;
};

void print_num(int i);

struct PrintNum
{
    void operator()(int i) const;
};

template <typename... Args>
class function;

template <typename R, typename... Args>
class function<R(Args...)>
{
public:
    /** construct empty function object */
    function() : m_functor(nullptr), m_invoke(nullptr), m_delete(nullptr), m_copy(nullptr) {}

    /** destruct function object */
    ~function();

    /** construct a valid function object from the copy of the given function pointer or functor */
    template <typename F, typename std::enable_if<
                              !std::is_same<typename std::decay<F>::type, function>::value, int>::type = 1>
    function(F &&functor) : function(1, cast_mem_fn(std::forward<F>(functor))) {}

    /** run function call */
    R operator()(Args... args) const;

    /** copy constructor */
    function(const function &other) : m_functor(other.m_copy ? (*other.m_copy)(other) : nullptr),
                                      m_invoke(other.m_invoke), m_delete(other.m_delete), m_copy(other.m_copy) {}

    /** move constructor */
    function(function &&other) : m_functor(other.m_functor), m_invoke(other.m_invoke),
                                 m_delete(other.m_delete), m_copy(other.m_copy)
    {
        other.m_functor = nullptr;
        other.m_invoke = nullptr;
        other.m_delete = nullptr;
        other.m_copy = nullptr;
    }

    /** copy assignment */
    function &operator=(const function &other);

    /** move assignment */
    function &operator=(function &&other)
    {
        if (m_delete)
            m_delete(*this);
        m_functor = other.m_functor;
        m_invoke = other.m_invoke;
        m_delete = other.m_delete;
        m_copy = other.m_copy;
        other.m_functor = nullptr;
        other.m_invoke = nullptr;
        other.m_delete = nullptr;
        other.m_copy = nullptr;
        return *this;
    }

private:
    template <typename F>
    function(int dummy, F &&functor) : m_functor(reinterpret_cast<char *>(new
                                                                          typename std::decay<F>::type(std::forward<F>(functor))))
    {
        typedef typename std::decay<F>::type functor_type;
        static_assert(std::is_same<R, decltype(invoke_impl<functor_type>(
                                          function(), std::declval<Args>()...))>::value,
                      "invalid functor type");
        static_assert(std::is_copy_constructible<functor_type>::value,
                      "uncopyable functor type");
        m_invoke = invoke_impl<functor_type>;
        m_delete = delete_impl<functor_type>;
        m_copy = copy_impl<functor_type>;
    }

    template <typename F>
    F &&cast_mem_fn(F &&f)
    {
        return static_cast<F &&>(f);
    }

    /** a pointer to class member cannot be casted to char* */
    /** conversion to a functor can solve this issue */
    template <typename CLASS, typename METHOD>
    class pmf_wrapper
    {
        METHOD CLASS::*m_pmf;

    public:
        pmf_wrapper(METHOD CLASS::*pmf) : m_pmf(pmf) {}

        R operator()(Args... args)
        {
            return invoke<METHOD>(static_cast<Args>(args)...);
        }

    private:
        template <typename T, typename std::enable_if<std::is_same<CLASS,
                                                                   typename std::decay<T>::type>::value,
                                                      int>::type = 1>
        T &&transfer(T &&inst)
        {
            return static_cast<T &&>(inst);
        }

        template <typename T, typename std::enable_if<std::is_same<CLASS,
                                                                   typename std::decay<decltype(*T())>::type>::value,
                                                      int>::type = 1>
        auto transfer(T &&ptr) -> decltype(*ptr)
        {
            return *ptr;
        }

        /** member function pointer */
        template <typename MT,
                  typename std::enable_if<std::is_function<MT>::value, int>::type = 1,
                  typename T, typename... SUBARGS>
        R invoke(T &&inst, SUBARGS &&...args)
        {
            return (transfer(std::forward<T>(inst)).*m_pmf)(std::forward<SUBARGS>(args)...);
        }

        /** data member pointer */
        template <typename MT,
                  typename std::enable_if<!std::is_function<MT>::value, int>::type = 1,
                  typename T>
        R invoke(T &&inst)
        {
            return transfer(std::forward<T>(inst)).*m_pmf;
        }
    };

    template <typename CLASS, typename METHOD>
    pmf_wrapper<CLASS, METHOD> cast_mem_fn(METHOD CLASS::*pmf)
    {
        return pmf_wrapper<CLASS, METHOD>(pmf);
    }

    template <typename F>
    static auto invoke_impl(const function &obj, Args... args) -> decltype(std::declval<F>()(static_cast<Args>(args)...))
    {
        return (*reinterpret_cast<F *>(obj.m_functor))(static_cast<Args>(args)...);
    }

    template <typename F>
    static void delete_impl(const function &obj)
    {
        delete reinterpret_cast<F *>(obj.m_functor);
    }

    template <typename F>
    static char *copy_impl(const function &obj)
    {
        return reinterpret_cast<char *>(new F(*reinterpret_cast<const F *>(obj.m_functor)));
    }

    /** pointer to the internal function pointer/functor object (on heap) */
    char *m_functor;

    /** call m_functor */
    R (*m_invoke)
    (const function &obj, Args... args);

    /** destroy m_functor */
    void (*m_delete)(const function &obj);

    /** copy m_functor */
    char *(*m_copy)(const function &obj);
};