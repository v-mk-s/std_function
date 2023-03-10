#include "std_function.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define FILE_LEN_MAX 10

int main(int argc, char *argv[])
{
    unsigned int file_mask = atoi(argv[1]);
    std::string filename = argv[2];
    std::vector<int> arr(FILE_LEN_MAX + 1);
    std::string s;
    std::ifstream file(filename);

    int i = 0;
    while (std::getline(file, s) && (i < FILE_LEN_MAX))
    {
        const int tmp{std::stoi(s)};
        arr[i] = tmp;

        ++i;
    }
    file.close();

    // main program
    auto factorial = [](int n)
    {
        function<int(int)> fac = [&](int n)
        { return (n < 2) ? 1 : n * fac(n - 1); };
        return fac(n);
    };


    // код ниже работает без Makefile!
    // с Makefile -> undefined reference :(
    /*
    // code for main tests taken from
    // https://en.cppreference.com/w/cpp/utility/functional/function

    // store a free function
    function<void(int)> f_display = print_num;
    f_display(-9);

    // store a lambda
    function<void()> f_display_42 = []()
    { print_num(42); };
    f_display_42();

    // store the result of a call to std::bind
    function<void()> f_display_31337 = std::bind(print_num, 31337);
    f_display_31337();

    // store a call to a member function
    function<void(const Foo &, int)> f_add_display = &Foo::print_add;
    const Foo foo(314159);
    f_add_display(foo, 1);
    f_add_display(314159, 1);

    // store a call to a data member accessor
    function<int(Foo const &)> f_num = &Foo::num_;
    std::cout << "num_: " << f_num(foo) << '\n';

    // store a call to a member function and object
    using std::placeholders::_1;
    function<void(int)> f_add_display2 = std::bind(&Foo::print_add, foo, _1);
    f_add_display2(2);

    // store a call to a member function and object ptr
    function<void(int)> f_add_display3 = std::bind(&Foo::print_add, &foo, _1);
    f_add_display3(3);

    // store a call to a function object
    function<void(int)> f_display_obj = PrintNum();
    f_display_obj(18);

    auto factorial = [](int n)
    {
        // store a lambda object to emulate "recursive lambda"; aware of extra overhead
        function<int(int)> fac = [&](int n)
        { return (n < 2) ? 1 : n * fac(n - 1); };
        // note that "auto fac = [&](int n){...};" does not work in recursive calls
        return fac(n);
    };

    for (int i{5}; i != 8; ++i)
    {
        std::cout << i << "! = " << factorial(i) << ";  ";
    }
    */

    std::cout << "OK";

    return 0;
}
