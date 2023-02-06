#pragma once

namespace msgs {
    enum class MessageType : unsigned short {
        KeepAlive = 0,
        StatusUpdate = 1,
        Stuff = 2
    };
}
