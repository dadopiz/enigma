#include <enigma/plugboard.h>

#include <cassert>

namespace enigma {

Plugboard::Plugboard()
    : cables_(13)
    , plugboard_(ALPHABET)
{}

char Plugboard::Translate(char letter) const {
    assert(is_valid(letter) && "letter not valid.");
    return plugboard_[to_index(letter)];
}

void Plugboard::Reset() {
    cables_ = 13;
    plugboard_ = ALPHABET;
}

bool Plugboard::Connect(char lhs, char rhs) {
    assert(is_valid(lhs) && is_valid(rhs) && "letters are not valid.");

    if(cables_ <= 0)
        return false;

    if(AreConnected(lhs, rhs))
        return false;

    std::swap(plugboard_[to_index(lhs)], plugboard_[to_index(rhs)]);
    --cables_;

    return true;
}

bool Plugboard::AreConnected(char lhs, char rhs) const {
    return (plugboard_[to_index(lhs)] != lhs) || (plugboard_[to_index(rhs)] != rhs);
}

}
