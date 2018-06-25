#ifndef ENIGMA_REFLECTOR_H
#define ENIGMA_REFLECTOR_H

#include <cassert>
#include <enigma/utils.h>

namespace enigma {

class Reflector {
public:
    Reflector(Letters reflector)
        : reflector_(std::move(reflector))
    {}

    char Translate(char letter) const {
        assert(is_valid(letter) && "Invalid letter.");
        return reflector_[to_index(letter)];
    }

private:
    const Letters reflector_;
};

}

#endif // ENIGMA_REFLECTOR_H
