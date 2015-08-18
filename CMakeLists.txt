set(the_description "The dataflow functionality")
ut_add_module(utdataflow utcore)


SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
UT_OPTION(UT_ENABLE_DTRACE "Enable DTrace tracing of eventqueue activity?" ON IF UNIX)

IF(UT_ENABLE_DTRACE)
  MESSAGE( STATUS "Enabled DTrace.")
  INCLUDE(dtrace)
  add_definitions("-DHAVE_DTRACE")
  include_directories(${CMAKE_BINARY_DIR})
ENDIF(UT_ENABLE_DTRACE)

ut_module_include_directories(${UBITRACK_CORE_DEPS_INCLUDE_DIR})
ut_glob_module_sources(HEADERS "src/*.h" "src/*/*.h" "src/*/*/*.h" SOURCES "src/*/*.cpp" "src/*/*/*.cpp")
ut_create_module(${TINYXML_LIBRARIES} ${LOG4CPP_LIBRARIES} ${LAPACK_LIBRARIES} ${Boost_LIBRARIES})

IF(UT_ENABLE_DTRACE)
  DTRACE_INSTRUMENT(utdataflow)
ENDIF(UT_ENABLE_DTRACE)
