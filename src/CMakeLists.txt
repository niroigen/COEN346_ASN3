add_library(example "")

SET (CMAKE_CXX_FLAGS_INIT "-Wc++11-extensions")

target_sources(
    example
    PRIVATE
        virtual_manager.cpp
        disk.cpp
        main.cpp
        main_memory.cpp
        vm_helper.cpp
    )

target_include_directories(
    example
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
    )