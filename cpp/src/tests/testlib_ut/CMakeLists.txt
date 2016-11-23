# add the executable
add_executable(testlib_ut testlib_ut.cpp)
target_link_libraries (testlib_ut testlib)

# add the install targets
install (TARGETS testlib_ut DESTINATION ${CMAKE_BINARY_DIR}/bin)
