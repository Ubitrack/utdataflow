cmake_minimum_required(VERSION 3.4.0)



project(ubitrack_dataflow VERSION 1.3.0 LANGUAGES CXX)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

include(cmake/UbitrackConfig)

option(ENABLE_UNITTESTS "Enable Unit Tests" FALSE)


add_subdirectory(src)

if(ENABLE_UNITTESTS)
  # add_subdirectory(tests)
endif(ENABLE_UNITTESTS)
