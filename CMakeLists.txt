set(the_description "The dataflow functionality")
ut_add_module(utdataflow utcore)


SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
UT_OPTION(UT_ENABLE_DTRACE "Enable DTrace tracing of eventqueue activity?" OFF)
UT_OPTION(UT_ENABLE_ETW "Enable Event Tracing of eventqueue activity?" OFF)

set(tracing_hdr_files "")
set(tracing_src_files "")

IF(UT_ENABLE_DTRACE)
  MESSAGE( STATUS "Enabled DTrace.")
  INCLUDE(dtrace)
  add_definitions("-DHAVE_DTRACE")
  add_definitions("-DENABLE_DATAFLOW_TRACING")
  include_directories(${CMAKE_BINARY_DIR})
  set(tracing_hdr_files ${tracing_hdr_files} "${CMAKE_BINARY_DIR}/utDataflow/probes_ubitrack_dtrace.h")
ENDIF(UT_ENABLE_DTRACE)

IF(UT_ENABLE_ETW)
  MESSAGE( STATUS "Enabled Event Tracing for Windows.")
  INCLUDE(etw)
  add_definitions("-DHAVE_ETW")
  add_definitions("-DENABLE_DATAFLOW_TRACING")
  include_directories(${CMAKE_BINARY_DIR})
  set(tracing_hdr_files ${tracing_hdr_files} "${CMAKE_BINARY_DIR}/utDataflow/probes_ubitrack_etw.h")
  set(tracing_src_files ${tracing_src_files} "${CMAKE_BINARY_DIR}/utDataflow/probes_ubitrack_etw.rc")
ENDIF(UT_ENABLE_ETW)

ut_module_include_directories(${UBITRACK_CORE_DEPS_INCLUDE_DIR})
ut_glob_module_sources(HEADERS "src/*.h" "src/*/*.h" "src/*/*/*.h" "${tracing_src_files}" SOURCES "src/*/*.cpp" "src/*/*/*.cpp" "${tracing_src_files}")
ut_create_module(${TINYXML_LIBRARIES} ${LOG4CPP_LIBRARIES} ${LAPACK_LIBRARIES} ${Boost_LIBRARIES})

IF(UT_ENABLE_DTRACE)
  DTRACE_INSTRUMENT(utdataflow)
ENDIF(UT_ENABLE_DTRACE)

IF(UT_ENABLE_ETW)
  ETW_INSTRUMENT(utdataflow)
ENDIF(UT_ENABLE_ETW)
