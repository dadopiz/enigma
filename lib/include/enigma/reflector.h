#ifndef ENIGMA_REFLECTOR_H
#define ENIGMA_REFLECTOR_H

#include <cassert>
#include <enigma/utils.h>

namespace enigma {

class ENIGMA_API Reflector {
public:
    Reflector(std::array<char, 27> reflector)
    : reflector_{std::move(reflector)}
    {}

    inline char Translate(char letter) const {
        assert(is_valid(letter) && "Invalid letter.");
        return reflector_[to_index(letter)];
    }

private:
    const std::array<char, 27> reflector_;
};

namespace historical {

struct reflector {
    static const Reflector B;
    static const Reflector C;
};

}

}

#endif // ENIGMA_REFLECTOR_H
