cmake_minimum_required (VERSION 3.6)

project(MessageFactory VERSION 1.0)

add_subdirectory(Message)

add_executable(messageFactory
    src/main.cpp
    )

set_property(TARGET messageFactory PROPERTY CXX_STANDARD 17)
target_compile_options(messageFactory PRIVATE -Wall -Wextra -Wpedantic -Werror)

target_include_directories(messageFactory
    PRIVATE
    include
)

target_link_libraries(messageFactory
    PRIVATE
    Message
)
