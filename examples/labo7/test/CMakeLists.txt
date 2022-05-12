project(Unittest)

SET(GTEST_LIBRARY "$ENV{GTEST_DIR}")
include_directories(${GTEST_LIBRARY}/include)
include_directories(../src)

add_executable(unittest ./../src/interval.cpp maintest.cpp intervaltest.cpp)
target_link_libraries(unittest ${GTEST_LIBRARY}/build/libgtest.a ${GTEST_LIBRARY}/build/libgtest_main.a)
