project(std_function_test)

set(EXE_SOURCES
	test.cpp
)

add_executable(std_function_test ${EXE_SOURCES})

target_link_libraries(std_function_test PRIVATE std_function_lib)
# set_target_properties(std_function_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})