#include "MessageFactory.hpp"
#include "Register.hpp"
#include <iostream>

class CustomMessage : public msgs::IMessage {
    public:
        ~CustomMessage() override = default;
        std::string_view getName() override { return "custom msg"; }


};

constexpr int CUSTOM_MSG = 55;

void showMessages() {
    // use the factory to create some messages
    auto msg1 = create(msgs::MessageType::KeepAlive);
    auto msg2 = create(msgs::MessageType::StatusUpdate);
    auto msg3 = create(msgs::MessageType::Stuff); // this has not message tied to it

    // print the names
    std::cout << msg1->getName() << "\n";
    std::cout << msg2->getName() << "\n";
    std::cout << msg3->getName() << "\n"; // should be unknown
}

void printCustom() {
    auto customMsg = create(static_cast<msgs::MessageType>(CUSTOM_MSG));
    std::cout << customMsg->getName() << "\n";
}

void doCustomMsg() {
    // register a custom message
    msgs::Register<static_cast<msgs::MessageType>(CUSTOM_MSG), CustomMessage> regCustom;
    printCustom();
}

void promptUserForMessage() {
    msgs::Register<static_cast<msgs::MessageType>(CUSTOM_MSG), CustomMessage> regCustom;

    std::cout << "Pick a msg (0, 1, 2, " << CUSTOM_MSG << "): ";
    int choice;

    // this specifically allow for input of invalid enum values, which should return an unknown message
    std::cin >> choice;

    // print out the message picked
    auto usermsg = create(static_cast<msgs::MessageType>(choice));
    std::cout << "You picked: " << usermsg->getName() << "\n";
}

int main() {

    // basic operation of the factory
    showMessages();

    // show how extending the messages with a custom message works
    doCustomMsg();

    // show RAII for message registration (i.e. custom message got unregistered
    printCustom();

    promptUserForMessage();

    return 0;
}
