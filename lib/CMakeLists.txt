project(std_function_library)

set(LIB_SOURCES
    std_function.cpp
)

add_library(std_function_lib STATIC ${LIB_SOURCES})
message(${CMAKE_SOURCE_DIR}/include)
target_include_directories(std_function_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
