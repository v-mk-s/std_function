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

 # Setup and run
    mkdir tmp
    cd tmp
    cmake ..
    make

# Run integration test
    python3 ../test/integr/grep_test.py
