#include <enigma/reflector.h>

namespace enigma {

Reflector::Reflector(Letters reflector)
    : reflector_(std::move(reflector))
{}

char Reflector::Translate(char letter) const {
    letter_assert(letter);
    return reflector_[to_index(letter)];
}

}
