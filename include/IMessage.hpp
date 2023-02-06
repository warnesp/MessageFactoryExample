#pragma once

#include <string_view>

namespace msgs {
    /// Base class for messages
    class IMessage {
        public:
            virtual ~IMessage() = default;

            /// get the name of the message
            virtual std::string_view getName() = 0;
        protected:
            IMessage() = default;
    };
}
