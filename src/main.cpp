#include "MessageFactory.hpp"

#include <iostream>

int main() {

    // use the factory to create some messages
    auto msg1 = create(msgs::MessageType::KeepAlive);
    auto msg2 = create(msgs::MessageType::StatusUpdate);
    auto msg3 = create(msgs::MessageType::Stuff);

    // print the names
    std::cout << msg1->getName() << "\n";
    std::cout << msg2->getName() << "\n";
    std::cout << msg3->getName() << "\n";

    std::cout << "Pick a msg: (0, 1, 2)";
    int choice;

    // this specifically allow for input of invalid enum values, which should return an unknown message
    std::cin >> choice;

    // print out the message picked
    auto msg4 = create(static_cast<msgs::MessageType>(choice));
    std::cout << "You picked: " << msg4->getName() << "\n";

    return 0;
}
