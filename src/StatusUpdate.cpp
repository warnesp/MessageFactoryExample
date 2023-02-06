#include "StatusUpdate.hpp"

#include "MessageType.hpp"
#include "Register.hpp"

using namespace msgs;

namespace statusupdate {
    Register<MessageType::StatusUpdate, StatusUpdate> reg;
}

std::string_view StatusUpdate::getName() {
    return "Status Update";
}
