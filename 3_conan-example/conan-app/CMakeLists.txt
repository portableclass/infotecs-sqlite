cmake_minimum_required(VERSION 3.15)
project(hello_conan)

if(EXISTS "${CMAKE_CURRENT_BINARY_DIR}/generators/conan_toolchain.cmake")
    include("${CMAKE_CURRENT_BINARY_DIR}/generators/conan_toolchain.cmake")
endif()

find_package(cxxopts CONFIG REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE cxxopts::cxxopts)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
