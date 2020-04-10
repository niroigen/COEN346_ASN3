add_executable(
    unit_tests
    test_main_memory.cpp
    test_disk.cpp
    test_virtual_manager.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    example
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )