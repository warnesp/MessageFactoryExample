#pragma once

#include "IMessage.hpp"
#include "MessageType.hpp"

#include <functional>
#include <memory>

namespace msgs {
    using Factory = std::function<std::unique_ptr<IMessage>()>;

    /// keeps registerFactory from being publicly available
    class BaseRegister final {
        static void registerFactory(MessageType const & type, Factory factory);
        template <MessageType, class> friend class Register;
    };

    /// Used to statically register a type to an enum
    template<MessageType TEnum, class TMsg>
    class Register final {

        /// factory for the given type
        static std::unique_ptr<IMessage> factory() { return std::make_unique<TMsg>(); }

        public:
            Register() {
                BaseRegister::registerFactory(TEnum, &factory);
            }
    };
}
