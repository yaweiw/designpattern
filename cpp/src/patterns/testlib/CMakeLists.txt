add_library(testlib testlib.cpp)

install (TARGETS testlib DESTINATION ${CMAKE_BINARY_DIR}/lib)
