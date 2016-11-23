add_library(cretional creational.cpp)

install (TARGETS creational DESTINATION ${PROJECT_BINARY_DIR}/lib)
install (FILES creational.h DESTINATION ${PROJECT_BINARY_DIR}/inc)