#include "std_function.h"

#include <cassert>
#include <stdexcept>

void test_func2()
{
    auto factorial = [](int n)
    {
        // store a lambda object to emulate "recursive lambda"; aware of extra overhead
        function<int(int)> fac = [&](int n)
        { return (n < 2) ? 1 : n * fac(n - 1); };
        // note that "auto fac = [&](int n){...};" does not work in recursive calls
        return fac(n);
    };

    // for (int i{5}; i != 8; ++i)
    // {
    //     std::cout << i << "! = " << factorial(i) << ";  ";
    // }

    // assert(f_display == print_num);

    std::cout << "[TEST OK]" << std::endl;
}

void test_func1()
{
    // // code for main tests taken from
    // // https://en.cppreference.com/w/cpp/utility/functional/function

    // // store a free function
    // function<void(int)> f_display = print_num;
    // f_display(-9);

    // // store a lambda
    // function<void()> f_display_42 = []()
    // { print_num(42); };
    // f_display_42();

    // // store the result of a call to std::bind
    // function<void()> f_display_31337 = std::bind(print_num, 31337);
    // f_display_31337();

    // // store a call to a member function
    // function<void(const Foo &, int)> f_add_display = &Foo::print_add;
    // const Foo foo(314159);
    // f_add_display(foo, 1);
    // f_add_display(314159, 1);

    // // store a call to a data member accessor
    // function<int(Foo const &)> f_num = &Foo::num_;
    // std::cout << "num_: " << f_num(foo) << '\n';

    // // store a call to a member function and object
    // using std::placeholders::_1;
    // function<void(int)> f_add_display2 = std::bind(&Foo::print_add, foo, _1);
    // f_add_display2(2);

    // // store a call to a member function and object ptr
    // function<void(int)> f_add_display3 = std::bind(&Foo::print_add, &foo, _1);
    // f_add_display3(3);

    // // store a call to a function object
    // function<void(int)> f_display_obj = PrintNum();
    // f_display_obj(18);

    // auto factorial = [](int n)
    // {
    //     // store a lambda object to emulate "recursive lambda"; aware of extra overhead
    //     function<int(int)> fac = [&](int n)
    //     { return (n < 2) ? 1 : n * fac(n - 1); };
    //     // note that "auto fac = [&](int n){...};" does not work in recursive calls
    //     return fac(n);
    // };

    std::cout << "[TEST OK]" << std::endl;
}

void test_func(0){
    function<void()> f_display = [](){ print_num(42); };
    f_display();
}

int main()
{
    test_func1();
    test_func2();
    return 0;
}
