cmake_minimum_required (VERSION 3.6)

project(MessageFactory VERSION 1.0)

add_executable(messageFactory
    src/main.cpp
    src/StatusUpdate.cpp
    src/UnknownMessage.cpp
    src/MessageFactory.cpp
    src/KeepAlive.cpp)

set_property(TARGET messageFactory PROPERTY CXX_STANDARD 17)

target_include_directories(messageFactory
    PRIVATE
    include
)

target_link_libraries(messageFactory
    PRIVATE
)
