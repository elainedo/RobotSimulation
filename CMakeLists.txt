cmake_minimum_required(VERSION 3.5)
project(robot-sim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(lib/nanogui)
include_directories(lib/nanogui/include)
include_directories(${NANOGUI_EXTRA_INCS})
add_definitions(${NANOGUI_EXTRA_DEFS})

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
add_executable(robot-sim ${SOURCE_FILES})
target_link_libraries(robot-sim nanogui ${NANOGUI_EXTRA_LIBS})