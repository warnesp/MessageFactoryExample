#include "MessageFactory.hpp"
#include "Register.hpp"
#include "UnknownMessage.hpp"

#include <map>

using namespace msgs;

std::map<MessageType, Factory> & messageMap() {
    // Meyer singleton
    static std::map<MessageType, Factory> singleton;
    return singleton;
}

std::unique_ptr<IMessage> msgs::create(MessageType const & type) {

    auto item = messageMap().find(type);
    if(item == messageMap().end()) {
        // didn't find the item, return unknown
        return std::make_unique<UnknownMessage>();
    } else {
        // call the found factory
        return item->second();
    }
}


void BaseRegister::registerFactory(MessageType const & type, Factory factory) {
    messageMap()[type] = factory;
}

void BaseRegister::unregisterFactory(MessageType const & type) {
    messageMap().erase(type);
}
