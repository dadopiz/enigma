#ifndef ENIGMA_ROTOR_H
#define ENIGMA_ROTOR_H

#include <cassert>
#include <enigma/utils.h>

namespace enigma {

class ENIGMA_API Rotor {
public:
    Rotor(std::array<char, 27> rotor, char notch)
    : rotor_(std::move(rotor))
    , notch_(notch)
    , ring_(0)
    , offset_(0)
    {}

    inline void RingStellung(char ring) {
        assert(is_valid(ring) && "ring not valid.");
        ring_ = to_index(ring);
    }

    inline void Turn() {
        offset_ = (offset_ + 1) % 26;
    }

    inline bool IsNotch() const {
        return to_char(offset_) == notch_;
    }

    //TODO: translate char

private:
    inline char Offset(char letter, std::size_t offset) const {
        return ALPHABET.at((to_index(letter) + offset + 26) % 26);
    }

    const std::array<char, 27> rotor_;
    const char notch_;

    std::size_t ring_;
    std::size_t offset_;
};

namespace historical {

struct rotor {
    static const Rotor I;
    static const Rotor II;
    static const Rotor III;
    static const Rotor IV;
    static const Rotor V;
};

}

}

#endif // ENIGMA_ROTOR_H
