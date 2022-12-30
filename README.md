# Implementation std::function (simplified)
Homework for the course industrial development in C++ (Technopark)

[DISTRIBUTION]  : <https://docs.google.com/spreadsheets/d/1SBwOcvxeQsJSgYD9QoMnDZc5UwioBjbNM4z8Ojmn25Y/edit#gid=0>
[INFO]          : <https://en.cppreference.com/w/cpp/utility/functional/function>
[TASK]          : function (std::function)

# Task description

std::function
Implement the simplest analogue of std::function, which can store any
functors and function pointers.

# Functional requirements
1) Store any functors and function pointers
2) Easy to track functors and function pointers

# Non-functional requirements

1) C++23 standard not supported (<=C++20)
2) Simplified analogue of std::function

# Implementation details

1) The implementation is based on the standard C++20 std::function implementation
2) To be continued


Build
------------
    mkdir tmp
    cd tmp
    cmake ..
    make
    make std_function_test
    make std_function
------------

Run unit tests
------------
    ./test/unit/std_function_test
------------

Run integration tests
------------
    cd ..
    ./test/integr/test.sh
    # (not working) .././test/integr/test.sh
    # (Optional) Integration tests are run from the project's root directory
------------
