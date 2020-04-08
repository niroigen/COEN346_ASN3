cmake_minimum_required(VERSION 3.5.1)
project(asn3)

set(SOURCES
    src/virtual_manager.cpp
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)