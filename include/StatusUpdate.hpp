#pragma once

#include "IMessage.hpp"

namespace msgs {
    class StatusUpdate : public IMessage {
        public:
            ~StatusUpdate() override = default;
            std::string_view getName() override;
    };
}
