#include "KeepAlive.hpp"

#include "MessageType.hpp"
#include "Register.hpp"

using namespace msgs;

namespace keepalive {
    Register<MessageType::KeepAlive, KeepAlive> reg;
}

std::string_view KeepAlive::getName() {
    return "Keep Alive";
}
