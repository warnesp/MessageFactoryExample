#pragma once

#include "IMessage.hpp"
#include "MessageType.hpp"

#include <memory>

namespace msgs {
    /// Creates a message from the given type, returns an Unknown Message if the type is not found
    std::unique_ptr<IMessage> create(MessageType const & type);
}
