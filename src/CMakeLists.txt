add_library(example "")

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