
add_library(Message SHARED
    src/KeepAlive.cpp
    src/MessageFactory.cpp
    src/UnknownMessage.cpp
    src/StatusUpdate.cpp
    )

set_property(TARGET Message PROPERTY CXX_STANDARD 17)
target_compile_options(Message PRIVATE -Wall -Wextra -Wpedantic -Werror)

target_include_directories(Message
    PUBLIC
    include
    )

