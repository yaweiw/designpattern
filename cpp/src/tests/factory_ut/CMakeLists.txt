# add the executable
add_executable(factory_ut factory_ut.cpp)
target_link_libraries (factory_ut factory)

# add the install targets
install (TARGETS factory_ut DESTINATION ${CMAKE_BINARY_DIR}/bin)
