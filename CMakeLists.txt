project(ubitrack_dataflow)

cmake_minimum_required(VERSION 3.4.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(KEEP_RPATHS)

include(cmake/UbitrackConfig)

# External Libraries (could this be solved with conan dependencies ??)
set(UBITRACK_EXTRA_LIBS )


add_subdirectory(src)

# add_subdirectory(tests)

file(GLOB _doc_files LIST_DIRECTORIES false "doc/bibliography.bib")
foreach(pfile ${_doc_files})
  string(REGEX REPLACE "^.*/doc/" "" pfile2 "${pfile}")
  GET_FILENAME_COMPONENT(fpath ${pfile2} PATH)
  IF(fpath)
    install(FILES ${pfile} DESTINATION "${UBITRACK_DOC_INSTALL_DIRECTORY}/${fpath}" COMPONENT doc)
  ELSE(fpath)
    install(FILES ${pfile} DESTINATION "${UBITRACK_DOC_INSTALL_DIRECTORY}" COMPONENT doc)
  ENDIF(fpath)
endforeach()
