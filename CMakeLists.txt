set(the_description "The dataflow functionality")

ut_add_module(utdataflow utcore)
ut_module_include_directories(${UBITRACK_CORE_DEPS_INCLUDE_DIR})
ut_glob_module_sources(HEADERS "src/*.h" "src/*/*.h" "src/*/*/*.h" "${tracing_src_files}" SOURCES "src/*/*.cpp" "src/*/*/*.cpp" "${tracing_src_files}")
ut_create_module(${TINYXML_LIBRARIES} ${LOG4CPP_LIBRARIES} ${LAPACK_LIBRARIES} ${Boost_LIBRARIES})
