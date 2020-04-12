add_library(example "")

target_sources(
    example
    PRIVATE
        virtual_manager.cpp
        disk.cpp
        main.cpp
        main_memory.cpp
        vm_helper.cpp
        scheduler_helper.cpp
    )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_include_directories(
    example
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
    )