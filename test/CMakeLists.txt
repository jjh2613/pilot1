include_directories(${JHUART_SOURCE_DIR}/src)
link_directories(${JHUART_BINARY_DIR}/src)

add_executable(uarttest serial_test.cpp)
target_link_libraries(uarttest JHUART)
