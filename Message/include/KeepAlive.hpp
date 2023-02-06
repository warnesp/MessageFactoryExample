#pragma once

#include "IMessage.hpp"

namespace msgs {
    class KeepAlive : public IMessage {
        public:
            ~KeepAlive() override = default;
            std::string_view getName() override;
    };
}
