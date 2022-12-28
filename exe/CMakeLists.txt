project(std_function_app)

set(EXE_SOURCES
	main.cpp
)

add_executable(std_function ${EXE_SOURCES})

target_link_libraries(std_function PRIVATE std_function_lib)
# set_target_properties(std_function PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})