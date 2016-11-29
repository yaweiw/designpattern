add_library(builder builder.cpp)
install (TARGETS builder DESTINATION ${CMAKE_BINARY_DIR}/lib)