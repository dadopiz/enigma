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

private:
    const std::array<char, 27> rotor_;
    const char notch_;

    std::size_t ring_;
    std::size_t offset_;
};

}

#endif // ENIGMA_ROTOR_H
