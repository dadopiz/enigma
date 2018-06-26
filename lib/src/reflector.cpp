#include <enigma/reflector.h>

#include <cassert>

namespace enigma {

Reflector::Reflector(Letters reflector)
    : reflector_(std::move(reflector))
{}

char Reflector::Translate(char letter) const {
    assert(is_valid(letter) && "Invalid letter.");
    return reflector_[to_index(letter)];
}

}
