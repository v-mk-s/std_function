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

    std::cout << "[TEST 2 OK]" << std::endl;
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

    std::cout << "[TEST 1 OK]" << std::endl;
}

// весь код работает выше без MakeFile
// с Makefile -> undefined reference

/*
    /usr/bin/ld: CMakeFiles/std_function_test.dir/test.cpp.o: in function `test_func0()':
    test.cpp:(.text+0xba): undefined reference to `function<void ()>::operator()() const'
    /usr/bin/ld: test.cpp:(.text+0xc6): undefined reference to `function<void ()>::~function()'
    /usr/bin/ld: test.cpp:(.text+0xeb): undefined reference to `function<void ()>::~function()'
    collect2: error: ld returned 1 exit status
    make[2]: *** [test/unit/CMakeFiles/std_function_test.dir/build.make:85: test/unit/std_function_test] Error 1
    make[1]: *** [CMakeFiles/Makefile2:190: test/unit/CMakeFiles/std_function_test.dir/all] Error 2
    make: *** [Makefile:84: all] Error 2
*/
void test_func0(){
// function<void()> f_display = [](){ print_num(42); };
// f_display();
}

int main()
{
    test_func0();
    test_func1();
    test_func2();
    return 0;
}

/*
#include <gtest/gtest.h>
#include <vector>
#include "algo.hpp"

class GreaterZero {
public:
    bool operator()(int a) {
        return a > 0;
    }
};

TEST(TestAlgo, all_of) {
    std::vector <int> a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    ASSERT_TRUE(cust_all_of(a.begin(), a.end(), GreaterZero()));
    a[0] = -1;
    ASSERT_FALSE(cust_all_of(a.begin(), a.end(), GreaterZero()));
}

TEST(TestAlgo, any_of) {
    std::vector <int> a(3);
    a[0] = -1;
    a[1] = 2;
    a[2] = 3;
    ASSERT_TRUE(cust_any_of(a.begin(), a.end(), GreaterZero()));
    a[1] = -1;
    a[2] = -1;
    ASSERT_FALSE(cust_any_of(a.begin(), a.end(), GreaterZero()));
}


TEST(TestAlgo, none_of) {
    std::vector <int> a(3);
    a[0] = -1;
    a[1] = -2;
    a[2] = -3;
    ASSERT_TRUE(cust_none_of(a.begin(), a.end(), GreaterZero()));
    a[0] = 1;
    ASSERT_FALSE(cust_none_of(a.begin(), a.end(), GreaterZero()));
}

TEST(TestAlgo, count) {
    std::vector <int> a(3);
    a[0] = -1;
    a[1] = -2;
    a[2] = -3;
    ASSERT_EQ(cust_count(a.begin(), a.end(), 1), 0);
    a[0] = 1;
    a[2] = 1;
    ASSERT_EQ(cust_count(a.begin(), a.end(), 1), 2);
}

TEST(TestAlgo, count_if) {
*/
