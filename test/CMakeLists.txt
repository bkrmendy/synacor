project(tests)

add_subdirectory(thirdparty/googletest)
include_directories(../include ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(tests src/main.cpp src/instruction_unit.cpp)
target_link_libraries(tests synacor gtest gtest_main)