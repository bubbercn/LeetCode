cmake_minimum_required(VERSION 3.0.0)
project(LeetCode VERSION 0.1.0)

# require C++11
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include(CTest)
enable_testing()
    
find_package(GTest CONFIG REQUIRED)

add_executable(LeetCode Test.cpp)

target_link_libraries(LeetCode PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
    
add_test(AllTestsInMain LeetCode)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

