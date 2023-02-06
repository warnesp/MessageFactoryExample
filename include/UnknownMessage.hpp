#pragma once

#include "IMessage.hpp"

namespace msgs {
    class UnknownMessage : public IMessage {
        public:
            ~UnknownMessage() override = default;
            std::string_view getName() override;
    };
}
