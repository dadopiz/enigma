#include <enigma/reflector.h>

#include <enigma/utils.h>

namespace enigma {

Reflector::Reflector(const std::string& reflector)
    : reflector_(reflector)
{}

char Reflector::Translate(char letter) const {
    letter_assert(letter);
    return reflector_[to_index(letter)];
}

}
