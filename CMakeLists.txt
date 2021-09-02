cmake_minimum_required(VERSION 3.0.0)
project(Promise VERSION 0.1.0 LANGUAGES CXX )

include(CTest)
enable_testing()


include_directories(include/)
add_library(${PROJECT_NAME} STATIC 
src/Promise.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
