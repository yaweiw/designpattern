# add the executable
add_executable(builder_ut builder_ut.cpp)
target_link_libraries (builder_ut builder)

# add the install targets
install (TARGETS builder_ut DESTINATION ${CMAKE_BINARY_DIR}/bin)
